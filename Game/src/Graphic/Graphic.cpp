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

#include <FileSystem/FileSystem.h>

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

	s32 m_BackBufferIndex;
	std::vector<u64> m_FrameFenceValues;

	Vec4 m_BackBufferClearColor;

	std::byte* m_Data[3];
	FileSystem::WorkHandle m_Handle[3];
}

void Graphic::Startup()
{
	m_Device.startup();
	Impl::preCalc(m_Device.getDevice());

	Rect screenRect{ 0.0f, 0.0f, static_cast<f32>(GetScreenWidth()), static_cast<f32>(GetScreenHeight()) };
	m_Viewport.set(screenRect, 0.0f, 1.0f);
	m_ScissorRect.set(screenRect);

	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING, GetBackBufferCount());
	m_CommandList.close();

	m_SwapChain.startup(m_Device, m_CommandQueue, TEXTURE_FORMAT::R8G8B8A8_UNORM,
		GetBackBufferCount(), GetScreenWidth(), GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	m_BackBufferDescriptor.startup(m_Device, DESCRIPTOR_TYPE::RENDER_TARGET, GetBackBufferCount());
	m_BackBuffers.resize(GetBackBufferCount());
	for (s32 i = 0; i < m_BackBuffers.size(); ++i)
	{
		m_BackBuffers[i].startupBackBuffer(m_SwapChain, i);
		m_BackBufferDescriptor.bindingRenderTarget(m_Device, m_BackBuffers[i], i);
	}

	m_FrameFence.startup(m_Device);
	m_FrameFenceValues.resize(GetBackBufferCount());
	m_FrameFenceValues[m_BackBufferIndex] = 1;

	const u64 size1 = FileSystem::GetFileSize(std::string{ Setting::GetDataPath() } + "video1.xp3");
	const u64 size2 = FileSystem::GetFileSize(std::string{ Setting::GetDataPath() } + "video2.xp3");
	const u64 size3 = FileSystem::GetFileSize(std::string{ Setting::GetDataPath() } + "video3.xp3");
	m_Data[0] = new std::byte[size1];
	m_Data[1] = new std::byte[size2];
	m_Data[2] = new std::byte[size3];
	m_Handle[0] = FileSystem::RequestRead(std::string{ Setting::GetDataPath() } + "video1.xp3", m_Data[0], size1);
	m_Handle[1] = FileSystem::RequestRead(std::string{ Setting::GetDataPath() } + "video2.xp3", m_Data[1], size2);
	m_Handle[2] = FileSystem::RequestRead(std::string{ Setting::GetDataPath() } + "video3.xp3", m_Data[2], size3);
}

void Graphic::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);
	m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);

	m_FrameFence.cleanup();
	m_BackBufferDescriptor.cleanup();
	for (auto& backBuffer : m_BackBuffers)backBuffer.cleanup();
	m_BackBuffers.clear();
	m_SwapChain.cleanup();
	m_CommandList.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
}

void Graphic::Update()
{
	if (m_Handle[0].isEnd() && m_Handle[1].isEnd() && m_Handle[2].isEnd())
	{
		m_BackBufferClearColor.m_f32Col.r = (std::sin(Global::GetAppTimeAll() * 1) + 1.0f) / 2.0f;
		m_BackBufferClearColor.m_f32Col.g = (std::sin(Global::GetAppTimeAll() * 2) + 1.0f) / 2.0f;
		m_BackBufferClearColor.m_f32Col.b = (std::sin(Global::GetAppTimeAll() * 5) + 1.0f) / 2.0f;
	}
	else
	{
		m_BackBufferClearColor.setZero();
	}
}

void Graphic::DrawBegin()
{
	m_CommandList.drawBegin(m_BackBufferIndex);

	m_CommandList.setViewport(m_Viewport);
	m_CommandList.setScissorRect(m_ScissorRect);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::RENDER_TARGET);

	m_CommandList.setRenderTargets(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), 1);
	m_CommandList.clearRenderTarget(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), m_BackBufferClearColor);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::PRESENT);
}

void Graphic::DrawEnd()
{
	m_CommandList.close();

	m_CommandQueue.executeCommandList(m_CommandList);

	m_SwapChain.present(1);

	const u64 prevFrameFenceValue = m_FrameFenceValues[m_BackBufferIndex];
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);

	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	if (m_FrameFence.getCompletedValue() < m_FrameFenceValues[m_BackBufferIndex])
	{
		m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);
	}
	m_FrameFenceValues[m_BackBufferIndex] = prevFrameFenceValue + 1;

}

CANDY_NAMESPACE_END
