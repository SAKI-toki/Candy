#include "GraphicSystem.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>
#include <Graphic/SwapChain/GraphicSwapChain.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>
#include <Graphic/ResourceLifetime/GraphicResourceLifetime.h>
#include <Graphic/Shader/GraphicShaderManager.h>
#include <Graphic/Texture/GraphicTextureUploder.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/System/GraphicSystemImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace System
{
	Viewport m_BackBufferViewport;
	ScissorRect m_BackBufferScissorRect;
	Device m_Device;
	CommandQueue m_CommandQueue;
	SwapChain m_SwapChain;
	std::vector<Buffer> m_BackBuffers;
	Descriptor m_BackBufferDescriptor;
	Fence m_FrameFence;

	s32 m_BackBufferIndex{};
	u64 m_FrameFenceValue{};
}

void System::Startup()
{
	m_Device.startup();
	impl::Startup(m_Device.getDevice());
	ResourceLifetime::Startup();

	Rect rect{ 0.0f, 0.0f, static_cast<f32>(Config::GetScreenWidth()), static_cast<f32>(Config::GetScreenHeight()) };
	m_BackBufferViewport.set(rect, 0.0f, 1.0f);
	m_BackBufferScissorRect.set(rect);

	m_CommandQueue.startup(m_Device, types::COMMAND_LIST_TYPE::RENDERING);

	m_SwapChain.startup(m_Device, m_CommandQueue, types::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		Config::GetBackBufferCount(), Config::GetScreenWidth(), Config::GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	m_BackBufferDescriptor.startup(m_Device, types::DESCRIPTOR_TYPE::RENDER_TARGET, Config::GetBackBufferCount());
	m_BackBuffers.resize(Config::GetBackBufferCount());
	for (s32 i = 0; i < m_BackBuffers.size(); ++i)
	{
		m_BackBuffers[i].startupBackBuffer(m_SwapChain, i);
		m_BackBuffers[i].setName("m_BackBuffers");
		m_BackBufferDescriptor.bindingBackBuffer(m_Device, i, m_BackBuffers[i]);
	}

	m_FrameFence.startup(m_Device);
	m_FrameFenceValue = 0;

	ShaderManager::Startup();
	TextureUploder::Startup();
}

void System::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValue);
	m_FrameFence.waitCpu(m_FrameFenceValue);

	TextureUploder::Cleanup();
	ResourceLifetime::Cleanup();
	m_FrameFence.cleanup();
	m_BackBufferDescriptor.cleanup();
	for (auto& backBuffer : m_BackBuffers)backBuffer.cleanup();
	m_BackBuffers.clear();
	m_SwapChain.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
	ShaderManager::Cleanup();
}

void System::Update()
{

}

void System::BeginDraw()
{
	TextureUploder::ExecuteUploadTexture(m_CommandQueue);
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

	ResourceLifetime::Flip(prevBackBufferIndex, m_BackBufferIndex);

	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValue);
}

void System::ExecuteCommandList(CommandList& _commandList)
{
	m_CommandQueue.executeCommandList(_commandList);
}

Device& System::GetDevice()
{
	return m_Device;
}

Buffer& System::GetCurrentBackBuffer()
{
	return m_BackBuffers[GetBackBufferIndex()];
}

Descriptor& System::GetBackBufferDescriptor()
{
	return m_BackBufferDescriptor;
}

DescriptorCpuHandle System::GetBackBufferDescriptorCpuHandle()
{
	return m_BackBufferDescriptor.getCpuHandle(GetBackBufferIndex());
}

const Viewport& System::GetBackBufferViewport()
{
	return m_BackBufferViewport;
}

const ScissorRect& System::GetBackBufferScissorRect()
{
	return m_BackBufferScissorRect;
}

s32 System::GetBackBufferIndex()
{
	return m_BackBufferIndex;
}

s32 System::GetNextBackBufferIndex()
{
	return core::LoopSize(m_BackBufferIndex + 1, 0, Config::GetBackBufferCount());
}

CANDY_GRAPHIC_NAMESPACE_END
