#include "SoundSystemImpl.h"

CANDY_SOUND_NAMESPACE_BEGIN

namespace System
{
	namespace Impl
	{
		ComPtr<IXAudio2> m_XAudio;
		IXAudio2MasteringVoice* m_MasteringVoice = nullptr;

		struct SoundInfo
		{
			IXAudio2SourceVoice* m_SourceVoice = nullptr;
			std::shared_ptr<std::byte[]> m_Buffer;
			ComPtr<IUnknown> m_Apo;
		};
		std::vector<SoundInfo> m_SoundInfos;

		struct Chunk
		{
			union
			{
				u32 m_Id;
				struct
				{
					char m_Ids[4];
				};
			};
			u32 m_Size;
		};
		struct RiffChunk
		{
			u32 m_FileFormat;
		};
		struct FmtChunk
		{
			WAVEFORMAT m_WaveFormat;
		};
	}

	void Impl::Startup()
	{
		CANDY_ASSERT_HRESULT(::CoInitializeEx(nullptr, COINIT_MULTITHREADED));
		CANDY_ASSERT_HRESULT(XAudio2Create(m_XAudio.GetAddressOf(), 0, XAUDIO2_DEFAULT_PROCESSOR));
		CANDY_ASSERT_HRESULT(m_XAudio->CreateMasteringVoice(&m_MasteringVoice));
	}

	void Impl::Cleanup()
	{
		m_XAudio.Reset();
		::CoUninitialize();
	}

	void Impl::Update()
	{
		auto removeItr = std::remove_if(m_SoundInfos.begin(), m_SoundInfos.end(),
			[](const auto& _soundInfo)
			{
				XAUDIO2_VOICE_STATE state{};
				_soundInfo.m_SourceVoice->GetState(&state);
				return state.BuffersQueued == 0;
			});
		for (auto itr = removeItr; itr != m_SoundInfos.end(); ++itr)
		{
			if (itr->m_SourceVoice)itr->m_SourceVoice->DestroyVoice();
		}
		m_SoundInfos.erase(removeItr, m_SoundInfos.end());
	}

	void Impl::CallSe(const std::string_view _soundName, const u32 _callSeFlag)
	{
		std::string path = std::format(R"({0}\Sound\{1})", core::Config::GetDataPath(), _soundName);
		auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
		if (!core::FileSystem::RequestReadNoWait(path, bufferInfo))
		{
			CANDY_LOG_ERR("サウンドファイルの読み込みに失敗", _soundName);
			return;
		}

		u32 offset = 0;
		WAVEFORMATEX waveFormatEx{};

		while (offset + sizeof(Chunk) <= bufferInfo->m_BufferSize)
		{
			const Chunk& chunk = *(Chunk*)(bufferInfo->m_Buffer.get() + offset);
			offset += sizeof(Chunk);

			switch (chunk.m_Id)
			{
			case CANDY_MAKE_FOURCC('R','I','F', 'F'):
			{
				if (offset + sizeof(RiffChunk) > bufferInfo->m_BufferSize)break;

				const RiffChunk& riffChunk = *(RiffChunk*)(bufferInfo->m_Buffer.get() + offset);
				offset += sizeof(RiffChunk);
				switch (riffChunk.m_FileFormat)
				{
				case CANDY_MAKE_FOURCC('W', 'A', 'V', 'E'):	break;
				default:
				{
					CANDY_LOG("未対応のファイルフォーマットです");
					return;
				}
				break;
				}
			}
			break;
			case CANDY_MAKE_FOURCC('f', 'm', 't', ' '):
			{
				if (offset + sizeof(FmtChunk) > bufferInfo->m_BufferSize)break;

				const FmtChunk& fmtChunk = *(FmtChunk*)(bufferInfo->m_Buffer.get() + offset);
				offset += chunk.m_Size;
				waveFormatEx.wFormatTag = fmtChunk.m_WaveFormat.wFormatTag;
				waveFormatEx.nChannels = fmtChunk.m_WaveFormat.nChannels;
				waveFormatEx.nSamplesPerSec = fmtChunk.m_WaveFormat.nSamplesPerSec;
				waveFormatEx.nAvgBytesPerSec = fmtChunk.m_WaveFormat.nAvgBytesPerSec;
				waveFormatEx.nBlockAlign = fmtChunk.m_WaveFormat.nBlockAlign;
				waveFormatEx.wBitsPerSample = waveFormatEx.nBlockAlign * 8 / waveFormatEx.nChannels;
				if (waveFormatEx.wFormatTag != 1)
				{
					CANDY_LOG("未対応の音声フォーマットです");
					return;
				}
			}
			break;
			case CANDY_MAKE_FOURCC('d', 'a', 't', 'a'):
			{
				if (offset + chunk.m_Size > bufferInfo->m_BufferSize)break;
				SoundInfo soundInfo;
				soundInfo.m_Buffer = bufferInfo->m_Buffer;
				CANDY_ASSERT_HRESULT(m_XAudio->CreateSourceVoice(&soundInfo.m_SourceVoice, &waveFormatEx));
				XAUDIO2_BUFFER xaudio2Buffer{};
				xaudio2Buffer.pAudioData = (const BYTE*)bufferInfo->m_Buffer.get() + offset;
				xaudio2Buffer.AudioBytes = chunk.m_Size;
				xaudio2Buffer.Flags = XAUDIO2_END_OF_STREAM;
				if (_callSeFlag & types::CALL_SE_FLAG_LOOP)xaudio2Buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
				soundInfo.m_SourceVoice->SubmitSourceBuffer(&xaudio2Buffer);
				soundInfo.m_SourceVoice->Start();
				m_SoundInfos.push_back(soundInfo);
				return;
			}
			break;
			case CANDY_MAKE_FOURCC('J', 'U', 'N', 'K'):
			{
				offset += chunk.m_Size;
			}
			break;
			default:
			{
				CANDY_LOG("未対応のチャンクです");
				return;
			}
			break;
			}
		}
	}
}

CANDY_SOUND_NAMESPACE_END
