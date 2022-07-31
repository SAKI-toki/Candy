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
			const std::byte* m_Buffer = nullptr;
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
			if (itr->m_Buffer)delete[] itr->m_Buffer;
		}
		m_SoundInfos.erase(removeItr, m_SoundInfos.end());
	}

	void Impl::CallSe(const std::string_view _soundName, const u32 _callSeFlag)
	{
		std::string path = std::format(R"({0}\Sound\{1})", core::Config::GetDataPath(), _soundName);
		const u64 bufSize = core::FileSystem::GetFileSize(path);
		std::byte* buf = new std::byte[bufSize];
		core::FileSystem::RequestReadNoWait(path, buf, bufSize);

		u32 offset = 0;
		WAVEFORMATEX waveFormatEx{};

		while (offset + sizeof(Chunk) <= bufSize)
		{
			const Chunk& chunk = *(Chunk*)(buf + offset);
			offset += sizeof(Chunk);

			switch (chunk.m_Id)
			{
			case MAKE_FOURCC('R','I','F', 'F'):
			{
				if (offset + sizeof(RiffChunk) > bufSize)break;

				const RiffChunk& riffChunk = *(RiffChunk*)(buf + offset);
				offset += sizeof(RiffChunk);
				switch (riffChunk.m_FileFormat)
				{
				case MAKE_FOURCC('W', 'A', 'V', 'E'):	break;
				default:
				{
					CANDY_LOG("未対応のファイルフォーマットです");
					return;
				}
				break;
				}
			}
			break;
			case MAKE_FOURCC('f', 'm', 't', ' '):
			{
				if (offset + sizeof(FmtChunk) > bufSize)break;

				const FmtChunk& fmtChunk = *(FmtChunk*)(buf + offset);
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
			case MAKE_FOURCC('d', 'a', 't', 'a'):
			{
				if (offset + chunk.m_Size > bufSize)break;
				SoundInfo soundInfo;
				soundInfo.m_Buffer = buf;
				CANDY_ASSERT_HRESULT(m_XAudio->CreateSourceVoice(&soundInfo.m_SourceVoice, &waveFormatEx));
				XAUDIO2_BUFFER xaudio2Buffer{};
				xaudio2Buffer.pAudioData = (const BYTE*)buf + offset;
				xaudio2Buffer.AudioBytes = chunk.m_Size;
				xaudio2Buffer.Flags = XAUDIO2_END_OF_STREAM;
				if (_callSeFlag & types::CALL_SE_FLAG_LOOP)xaudio2Buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
				soundInfo.m_SourceVoice->SubmitSourceBuffer(&xaudio2Buffer);

				/*CANDY_ASSERT_HRESULT(XAudio2CreateReverb(soundInfo.m_Apo.GetAddressOf()));
				XAUDIO2_EFFECT_DESCRIPTOR descriptor;
				descriptor.InitialState = true;
				descriptor.OutputChannels = 2;
				descriptor.pEffect = soundInfo.m_Apo.Get();
				XAUDIO2_EFFECT_CHAIN chain;
				chain.EffectCount = 1;
				chain.pEffectDescriptors = &descriptor;
				soundInfo.m_SourceVoice->SetEffectChain(&chain);
				XAUDIO2FX_REVERB_PARAMETERS reverbParameters;
				reverbParameters.ReflectionsDelay = XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_DELAY;
				reverbParameters.ReverbDelay = XAUDIO2FX_REVERB_DEFAULT_REVERB_DELAY;
				reverbParameters.RearDelay = XAUDIO2FX_REVERB_DEFAULT_REAR_DELAY;
				reverbParameters.PositionLeft = XAUDIO2FX_REVERB_DEFAULT_POSITION;
				reverbParameters.PositionRight = XAUDIO2FX_REVERB_DEFAULT_POSITION;
				reverbParameters.PositionMatrixLeft = XAUDIO2FX_REVERB_DEFAULT_POSITION_MATRIX;
				reverbParameters.PositionMatrixRight = XAUDIO2FX_REVERB_DEFAULT_POSITION_MATRIX;
				reverbParameters.EarlyDiffusion = XAUDIO2FX_REVERB_DEFAULT_EARLY_DIFFUSION;
				reverbParameters.LateDiffusion = XAUDIO2FX_REVERB_DEFAULT_LATE_DIFFUSION;
				reverbParameters.LowEQGain = XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_GAIN;
				reverbParameters.LowEQCutoff = XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_CUTOFF;
				reverbParameters.HighEQGain = XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_GAIN;
				reverbParameters.HighEQCutoff = XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_CUTOFF;
				reverbParameters.RoomFilterFreq = XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_FREQ;
				reverbParameters.RoomFilterMain = XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_MAIN;
				reverbParameters.RoomFilterHF = XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_HF;
				reverbParameters.ReflectionsGain = XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_GAIN;
				reverbParameters.ReverbGain = XAUDIO2FX_REVERB_DEFAULT_REVERB_GAIN;
				reverbParameters.DecayTime = XAUDIO2FX_REVERB_DEFAULT_DECAY_TIME;
				reverbParameters.Density = XAUDIO2FX_REVERB_DEFAULT_DENSITY;
				reverbParameters.RoomSize = XAUDIO2FX_REVERB_DEFAULT_ROOM_SIZE;
				reverbParameters.WetDryMix = XAUDIO2FX_REVERB_DEFAULT_WET_DRY_MIX;
				CANDY_ASSERT_HRESULT(soundInfo.m_SourceVoice->SetEffectParameters(0, &reverbParameters, sizeof(reverbParameters)));*/

				soundInfo.m_SourceVoice->Start();
				m_SoundInfos.push_back(soundInfo);
				return;
			}
			break;
			case MAKE_FOURCC('J', 'U', 'N', 'K'):
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
