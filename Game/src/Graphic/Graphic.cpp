#include "Graphic.h"
#include "Device/GraphicDevice.h"
#include "CommandQueue/GraphicCommandQueue.h"
#include "CommandList/GraphicCommandList.h"
#include "SwapChain/GraphicSwapChain.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	Device m_Device;
	CommandQueue m_CommandQueue;
	CommandList m_CommandList;
	SwapChain m_SwapChain;
}

void Graphic::Startup()
{
	m_Device.startup();
	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_SwapChain.startup(m_Device, m_CommandQueue, TEXTURE_FORMAT::R8G8B8A8_UNORM,
		GetFrameCount(), GetScreenWidth(), GetScreenHeight());
}

void Graphic::Cleanup()
{
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

}

void Graphic::DrawEnd()
{
	m_SwapChain.present(1);
}

CANDY_NAMESPACE_END
