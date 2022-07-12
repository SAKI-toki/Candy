#include "GraphicCommandQueue.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandList/GraphicCommandList.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

void CommandQueue::startup(const Device& _device, const types::COMMAND_LIST_TYPE _commandListType)
{
	CommandQueueImpl::startup(_device.getDevice(), _commandListType);
}

void CommandQueue::cleanup()
{
	CommandQueueImpl::cleanup();
}

void CommandQueue::executeCommandList(CommandList& _commandList)const
{
	CommandQueueImpl::executeCommandList(_commandList.getCommandList());
}

CANDY_GRAPHIC_NAMESPACE_END
