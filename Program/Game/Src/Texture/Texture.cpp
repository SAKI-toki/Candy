#include "Texture.h"
#include <Graphic/Graphic.h>
#include <Graphic/CommandList/GraphicCommandList.h>
#include <Graphic/Fence/GraphicFence.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace Texture
{
	struct UploadBufferInfo
	{
		Graphic::Buffer m_DstBuffer;
		Graphic::Buffer m_SrcBuffer;
	};
	std::vector<UploadBufferInfo> m_UploadBufferInfos;
	Graphic::CommandList m_CommandList;
}

void Texture::Startup()
{
	m_CommandList.startup(Graphic::GetDevice(), Graphic::COMMAND_LIST_TYPE::RENDERING, Graphic::GetBackBufferCount());
	m_CommandList.close();
}

void Texture::Cleanup()
{
	m_UploadBufferInfos.clear();

	m_CommandList.cleanup();
}

void Texture::ExecuteUploadTexture(const Graphic::CommandQueue& _commandQueue)
{
	if (m_UploadBufferInfos.empty())return;
	m_CommandList.preDraw(Graphic::GetBackBufferIndex());
	for (auto& uploadBufferInfo : m_UploadBufferInfos)
	{
		m_CommandList.copyTexture(Graphic::GetDevice(), uploadBufferInfo.m_DstBuffer, uploadBufferInfo.m_SrcBuffer);
	}
	m_UploadBufferInfos.clear();
	m_CommandList.close();
	_commandQueue.executeCommandList(m_CommandList);
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
	m_UploadBufferInfos.push_back(uploadBufferInfo);
}

CANDY_NAMESPACE_END
