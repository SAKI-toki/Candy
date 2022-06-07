#include "Graphic.h"
#include "Device/GraphicDevice.h"
#include "CommandQueue/GraphicCommandQueue.h"
#include "CommandList/GraphicCommandList.h"
#include "SwapChain/GraphicSwapChain.h"
#include "Fence/GraphicFence.h"
#include "Buffer/GraphicBuffer.h"
#include "Viewport/GraphicViewport.h"
#include "ScissorRect/GraphicScissorRect.h"
#include "Descriptor/GraphicDescriptor.h"
#include "RootSignature/GraphicRootSignature.h"
#include "Pipeline/GraphicPipeline.h"
#include "BufferView/Vertex/GraphicVertexBufferView.h"
#include "BufferView/Index/GraphicIndexBufferView.h"
#include "ResourceManager/GraphicResourceManager.h"
#include <Shader/Shader.h>
#include <Input/Input.h>
#include <Texture/Texture.h>

#include <FileSystem/FileSystem.h>

#include <Texture/DDS/ReadDDS.h>

#if PLATFORM_WIN
#include "Platform/Win/GraphicImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	Viewport m_Viewport;
	ScissorRect m_ScissorRect;
	Device m_Device;
	CommandQueue m_CommandQueue;
	CommandList m_CommandList;
	SwapChain m_SwapChain;
	std::vector<Buffer> m_BackBuffers;
	Descriptor m_BackBufferDescriptor;
	Fence m_FrameFence;
	Buffer m_DepthStencilBuffer;
	Descriptor m_DepthStencilBufferDescriptor;

	s32 m_BackBufferIndex;
	u64 m_FrameFenceValue;
}

void Graphic::Startup()
{
	m_Device.startup();
	Impl::Startup(m_Device.getDevice());
	ResourceManager::Startup();

	Rect screenRect{ 0.0f, 0.0f, static_cast<f32>(GetScreenWidth()), static_cast<f32>(GetScreenHeight()) };
	m_Viewport.set(screenRect, 0.0f, 1.0f);
	m_ScissorRect.set(screenRect);

	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING, GetBackBufferCount());
	m_CommandList.close();

	m_SwapChain.startup(m_Device, m_CommandQueue, GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		GetBackBufferCount(), GetScreenWidth(), GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	m_BackBufferDescriptor.startup(m_Device, DESCRIPTOR_TYPE::RENDER_TARGET, GetBackBufferCount());
	m_BackBuffers.resize(GetBackBufferCount());
	for (s32 i = 0; i < m_BackBuffers.size(); ++i)
	{
		m_BackBuffers[i].startupBackBuffer(m_SwapChain, i);
		m_BackBufferDescriptor.bindingBackBuffer(m_Device, i, m_BackBuffers[i]);
	}

	BufferStartupInfo depthStencilBufferStartupInfo;
	depthStencilBufferStartupInfo.setDepthStencilStartupInfo(GRAPHIC_FORMAT::D24_UNORM_S8_UINT, GetScreenWidth(), GetScreenHeight());
	m_DepthStencilBufferDescriptor.startup(m_Device, DESCRIPTOR_TYPE::DEPTH_STENCIL, 1);
	m_DepthStencilBuffer.startup(m_Device, depthStencilBufferStartupInfo);
	m_DepthStencilBufferDescriptor.bindingDepthStencil(m_Device, 0, m_DepthStencilBuffer, GRAPHIC_FORMAT::D24_UNORM_S8_UINT);

	m_FrameFence.startup(m_Device);
	m_FrameFenceValue = 0;

	Shader::Startup();
	Texture::Startup();
}

void Graphic::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValue);
	m_FrameFence.waitCpu(m_FrameFenceValue);

	Texture::Cleanup();

	ResourceManager::Cleanup();
	m_FrameFence.cleanup();
	m_DepthStencilBufferDescriptor.cleanup();
	m_DepthStencilBuffer.cleanup();
	m_BackBufferDescriptor.cleanup();
	for (auto& backBuffer : m_BackBuffers)backBuffer.cleanup();
	m_BackBuffers.clear();
	m_SwapChain.cleanup();
	m_CommandList.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
	Shader::Cleanup();
}

void Graphic::Update()
{

}

void Graphic::PreDraw()
{
	Texture::ExecuteUploadTexture(m_CommandQueue);

	m_CommandList.preDraw(m_BackBufferIndex);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::RENDER_TARGET);

	m_CommandList.setViewport(m_Viewport);
	m_CommandList.setScissorRect(m_ScissorRect);

	m_CommandList.setRenderTargetsDepthStencil(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), 1,
		m_DepthStencilBufferDescriptor.getCpuHandle(0));
	m_CommandList.clearRenderTarget(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), GetColorRGB32(0x20, 0x20, 0x20));
	m_CommandList.clearDepthStencil(m_DepthStencilBufferDescriptor.getCpuHandle(0), 1.0f, 0);
	ResourceManager::Regist(m_BackBuffers[m_BackBufferIndex]);
	ResourceManager::Regist(m_DepthStencilBuffer);
	ResourceManager::Regist(m_BackBufferDescriptor);
	ResourceManager::Regist(m_DepthStencilBufferDescriptor);
}

void Graphic::PostDraw()
{
	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::PRESENT);

	m_CommandList.close();
	m_CommandQueue.executeCommandList(m_CommandList);
}

void Graphic::Flip()
{
	m_SwapChain.present(1);

	const s32 prevBackBufferIndex = std::exchange(m_BackBufferIndex, m_SwapChain.getBackBufferIndex());

	if (m_FrameFence.getCompletedValue() < m_FrameFenceValue)
	{
		m_FrameFence.waitCpu(m_FrameFenceValue);
	}
	m_FrameFenceValue = m_FrameFenceValue + 1;

	ResourceManager::Flip(prevBackBufferIndex, m_BackBufferIndex);

	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValue);
}

Graphic::Device& Graphic::GetDevice()
{
	return m_Device;
}

Graphic::CommandList& Graphic::GetCommandList()
{
	return m_CommandList;
}

Graphic::Descriptor& Graphic::GetBackBufferDescriptor()
{
	return m_BackBufferDescriptor;
}

s32 Graphic::GetBackBufferIndex()
{
	return m_BackBufferIndex;
}

CANDY_NAMESPACE_END
