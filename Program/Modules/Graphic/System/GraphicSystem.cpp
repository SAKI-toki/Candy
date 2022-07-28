#include "GraphicSystem.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>
#include <Graphic/CommandList/GraphicCommandList.h>
#include <Graphic/SwapChain/GraphicSwapChain.h>
#include <Graphic/Fence/GraphicFence.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/BufferView/Vertex/GraphicVertexBufferView.h>
#include <Graphic/BufferView/Index/GraphicIndexBufferView.h>
#include <Graphic/ResourceManager/GraphicResourceManager.h>
#include <Graphic/Shader/GraphicShaderManager.h>
#include <Graphic/Texture/GraphicTexture.h>
#include <Core/FileSystem/FileSystem.h>

#if PLATFORM_WIN
#include "Platform/Win/GraphicImpl.h"
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace System
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

void System::Startup()
{
	m_Device.startup();
	impl::Startup(m_Device.getDevice());
	ResourceManager::Startup();

	Rect screenRect{ 0.0f, 0.0f, static_cast<f32>(Config::GetScreenWidth()), static_cast<f32>(Config::GetScreenHeight()) };
	m_Viewport.set(screenRect, 0.0f, 1.0f);
	m_ScissorRect.set(screenRect);

	m_CommandQueue.startup(m_Device, types::COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, types::COMMAND_LIST_TYPE::RENDERING, Config::GetBackBufferCount());
	m_CommandList.close();

	m_SwapChain.startup(m_Device, m_CommandQueue, types::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		Config::GetBackBufferCount(), Config::GetScreenWidth(), Config::GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	m_BackBufferDescriptor.startup(m_Device, types::DESCRIPTOR_TYPE::RENDER_TARGET, Config::GetBackBufferCount());
	m_BackBuffers.resize(Config::GetBackBufferCount());
	for (s32 i = 0; i < m_BackBuffers.size(); ++i)
	{
		m_BackBuffers[i].startupBackBuffer(m_SwapChain, i);
		m_BackBufferDescriptor.bindingBackBuffer(m_Device, i, m_BackBuffers[i]);
	}

	BufferStartupInfo depthStencilBufferStartupInfo;
	depthStencilBufferStartupInfo.setDepthStencilStartupInfo(types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT, 
		Config::GetScreenWidth(), Config::GetScreenHeight());
	m_DepthStencilBufferDescriptor.startup(m_Device, types::DESCRIPTOR_TYPE::DEPTH_STENCIL, 1);
	m_DepthStencilBuffer.startup(m_Device, depthStencilBufferStartupInfo);
	m_DepthStencilBufferDescriptor.bindingDepthStencil(m_Device, 0, m_DepthStencilBuffer, types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT);

	m_FrameFence.startup(m_Device);
	m_FrameFenceValue = 0;

	ShaderManager::Startup();
	TextureManager::Startup();
}

void System::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValue);
	m_FrameFence.waitCpu(m_FrameFenceValue);

	TextureManager::Cleanup();

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
	ShaderManager::Cleanup();
}

void System::Update()
{

}

void System::PreDraw()
{
	TextureManager::ExecuteUploadTexture(m_CommandQueue);

	m_CommandList.preDraw(m_BackBufferIndex);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, types::BARRIER_STATE::RENDER_TARGET);

	m_CommandList.setViewport(m_Viewport);
	m_CommandList.setScissorRect(m_ScissorRect);

	m_CommandList.setRenderTargetsDepthStencil(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), 1,
		m_DepthStencilBufferDescriptor.getCpuHandle(0));
	m_CommandList.clearRenderTarget(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), core::GetColorRGB32(0x20, 0x20, 0x20));
	m_CommandList.clearDepthStencil(m_DepthStencilBufferDescriptor.getCpuHandle(0), 1.0f, 0);
	ResourceManager::Regist(m_BackBuffers[m_BackBufferIndex]);
	ResourceManager::Regist(m_DepthStencilBuffer);
	ResourceManager::Regist(m_BackBufferDescriptor);
	ResourceManager::Regist(m_DepthStencilBufferDescriptor);
}

void System::PostDraw()
{
	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, types::BARRIER_STATE::PRESENT);

	m_CommandList.close();
	m_CommandQueue.executeCommandList(m_CommandList);
}

void System::Flip()
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

Device& System::GetDevice()
{
	return m_Device;
}

CommandList& System::GetCommandList()
{
	return m_CommandList;
}

Descriptor& System::GetBackBufferDescriptor()
{
	return m_BackBufferDescriptor;
}

s32 System::GetBackBufferIndex()
{
	return m_BackBufferIndex;
}

CANDY_GRAPHIC_NAMESPACE_END
