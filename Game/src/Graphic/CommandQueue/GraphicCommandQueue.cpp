#include "GraphicCommandQueue.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandQueue::startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType)
	{
		CommandQueueImpl::startup(_device.getDevice(), _commandListType);
	}

	void CommandQueue::cleanup()
	{
		CommandQueueImpl::cleanup();
	}

	void CommandQueue::executeCommandList(CommandList& _commandList)
	{
		CommandQueueImpl::executeCommandList(_commandList.getCommandList());
	}
}

CANDY_NAMESPACE_END
