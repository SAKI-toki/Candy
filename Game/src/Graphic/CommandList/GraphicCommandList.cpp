#include "GraphicCommandList.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandList::startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType)
	{
		CommandListImpl::startup(_device.getDevice(), _commandListType);
	}

	void CommandList::cleanup()
	{
		CommandListImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
