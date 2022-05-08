#include "Texture.h"
#include <Graphic/Graphic.h>
#include <Graphic/CommandList/GraphicCommandList.h>
#include <Graphic/Fence/GraphicFence.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>

CANDY_NAMESPACE_BEGIN

namespace Texture
{
	struct UploadBufferInfo
	{
		Graphic::Buffer m_DstBuffer;
		Graphic::Buffer m_SrcBuffer;
	};
	std::vector<std::vector<UploadBufferInfo>> m_UploadBufferInfoLists;
	Graphic::CommandList m_CommandList;
}

void Texture::Startup()
{
	m_UploadBufferInfoLists.resize(Graphic::GetBackBufferCount());
	m_CommandList.startup(Graphic::GetDevice(), Graphic::COMMAND_LIST_TYPE::RENDERING, Graphic::GetBackBufferCount());
	m_CommandList.close();
}

void Texture::Cleanup()
{
	for (auto& uploadBufferInfoList : m_UploadBufferInfoLists)
	{
		for (auto& uploadBufferInfo : uploadBufferInfoList)
		{
			uploadBufferInfo.m_DstBuffer.cleanup();
			uploadBufferInfo.m_SrcBuffer.cleanup();
		}
		uploadBufferInfoList.clear();
	}
	m_UploadBufferInfoLists.clear();

	m_CommandList.cleanup();
}

void Texture::ExecuteUploadTexture(const Graphic::CommandQueue& _commandQueue)
{
	m_CommandList.preDraw(Graphic::GetBackBufferIndex());
	const s32 backBufferIndex = Graphic::GetBackBufferIndex();
	for (auto& uploadBufferInfo : m_UploadBufferInfoLists[backBufferIndex])
	{
		m_CommandList.copyTexture(Graphic::GetDevice(), uploadBufferInfo.m_DstBuffer, uploadBufferInfo.m_SrcBuffer);
		uploadBufferInfo.m_DstBuffer.translationBarrier(m_CommandList, Graphic::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
	}
	m_CommandList.close();
	_commandQueue.executeCommandList(m_CommandList);
}

void Texture::PostDraw()
{
	const s32 backBufferIndex = Graphic::GetBackBufferIndex();
	for (auto& uploadBufferInfo : m_UploadBufferInfoLists[backBufferIndex])
	{
		uploadBufferInfo.m_DstBuffer.cleanup();
		uploadBufferInfo.m_SrcBuffer.cleanup();
	}
	m_UploadBufferInfoLists[backBufferIndex].clear();
}

void Texture::CreateTexture(Graphic::Buffer& _buffer, const std::byte* const _pixels, const u64 _size)
{
	Graphic::Buffer uploaderBuffer;
	Graphic::BufferStartupInfo uploaderBufferStartupInfo;
	uploaderBufferStartupInfo.setBufferStartupInfo(_size);
	uploaderBuffer.startup(Graphic::GetDevice(), uploaderBufferStartupInfo);
	uploaderBuffer.store(_pixels, _size, 0);

	UploadBufferInfo uploadBufferInfo;
	uploadBufferInfo.m_SrcBuffer = uploaderBuffer;
	uploadBufferInfo.m_DstBuffer = _buffer;
	m_UploadBufferInfoLists[Graphic::GetBackBufferIndex()].push_back(uploadBufferInfo);
}

CANDY_NAMESPACE_END
