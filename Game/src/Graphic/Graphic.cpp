#include "Graphic.h"
#include "Device/GraphicDevice.h"
#include "CommandQueue/GraphicCommandQueue.h"
#include "CommandList/GraphicCommandList.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	Device m_Device;
	CommandQueue m_CommandQueue;
	CommandList m_CommandList;
}

void Graphic::Startup()
{
	m_Device.startup();
	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
}

void Graphic::Cleanup()
{
	m_CommandList.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
}

void Graphic::Update()
{

}

CANDY_NAMESPACE_END
