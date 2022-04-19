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
}

CANDY_NAMESPACE_END
