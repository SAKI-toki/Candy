/*****************************************************************//**
 * \file   GraphicTexture.cpp
 * \brief  テクスチャ
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicTexture.h"
#include <Graphic/Graphic.h>
#include <Graphic/CommandList/GraphicCommandList.h>
#include <Graphic/Fence/GraphicFence.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>
#include <Core/FileSystem/FileSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace TextureManager
{
	struct UploadBufferInfo
	{
		Buffer m_DstBuffer;
		Buffer m_SrcBuffer;
	};
	std::vector<UploadBufferInfo> m_UploadBufferInfos;
	CommandList m_CommandList;
}

// 初期化
void TextureManager::Startup()
{
	m_CommandList.startup(System::GetDevice(), types::COMMAND_LIST_TYPE::RENDERING, Config::GetBackBufferCount());
	m_CommandList.close();
}

// 破棄
void TextureManager::Cleanup()
{
	m_UploadBufferInfos.clear();

	m_CommandList.cleanup();
}

// アップロードテクスチャの実行
void TextureManager::ExecuteUploadTexture(const CommandQueue& _commandQueue)
{
	if (m_UploadBufferInfos.empty())return;
	m_CommandList.preDraw(System::GetBackBufferIndex());
	for (auto& uploadBufferInfo : m_UploadBufferInfos)
	{
		m_CommandList.copyTexture(System::GetDevice(), uploadBufferInfo.m_DstBuffer, uploadBufferInfo.m_SrcBuffer);
	}
	m_UploadBufferInfos.clear();
	m_CommandList.close();
	_commandQueue.executeCommandList(m_CommandList);
}

// テクスチャの作成
void TextureManager::CreateTexture(Buffer& _buffer, const std::byte* const _pixels, const u64 _size)
{
	Buffer uploaderBuffer;
	BufferStartupInfo uploaderBufferStartupInfo;
	uploaderBufferStartupInfo.setBufferStartupInfo(_size);
	uploaderBuffer.startup(System::GetDevice(), uploaderBufferStartupInfo);
	uploaderBuffer.store(_pixels, _size, 0);

	UploadBufferInfo uploadBufferInfo;
	uploadBufferInfo.m_SrcBuffer = uploaderBuffer;
	uploadBufferInfo.m_DstBuffer = _buffer;
	m_UploadBufferInfos.push_back(uploadBufferInfo);
}

CANDY_GRAPHIC_NAMESPACE_END
