#include "Graphic.h"
#include "Device/GraphicDevice.h"
#include "CommandQueue/GraphicCommandQueue.h"
#include "CommandList/GraphicCommandList.h"
#include "SwapChain/GraphicSwapChain.h"
#include "Fence/GraphicFence.h"
#include "Buffer/BackBuffer/GraphicBackBuffer.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	Device m_Device;
	CommandQueue m_CommandQueue;
	CommandList m_CommandList;
	SwapChain m_SwapChain;
	std::vector<BackBuffer> m_BackBuffers;
	Fence m_FrameFence;


	s32 m_BackBufferIndex;
	std::vector<u64> m_FrameFenceValues;
}

void Graphic::Startup()
{
	m_Device.startup();

	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING, GetBackBufferCount());
	m_CommandList.close();

	m_SwapChain.startup(m_Device, m_CommandQueue, TEXTURE_FORMAT::R8G8B8A8_UNORM,
		GetBackBufferCount(), GetScreenWidth(), GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();
	m_BackBuffers.resize(GetBackBufferCount());
	for (s32 i=0;i< m_BackBuffers.size();++i)
	{
		m_BackBuffers[i].startup(m_SwapChain, i);
	}

	m_FrameFence.startup(m_Device);
	m_FrameFenceValues.resize(GetBackBufferCount());
	m_FrameFenceValues[m_BackBufferIndex] = 1;
}

void Graphic::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);
	m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);

	for (auto& backBuffer : m_BackBuffers)backBuffer.cleanup();
	m_BackBuffers.clear();
	m_SwapChain.cleanup();
	m_CommandList.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
}

void Graphic::Update()
{

}

void Graphic::DrawBegin()
{
	m_CommandList.drawBegin(m_BackBufferIndex);
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
