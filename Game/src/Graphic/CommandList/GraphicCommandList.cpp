#include "GraphicCommandList.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandList::startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount)
	{
		CommandListImpl::startup(_device.getDevice(), _commandListType, _backBufferCount);
	}

	void CommandList::cleanup()
	{
		CommandListImpl::cleanup();
	}

	void CommandList::drawBegin(const s32 _backBufferIndex)
	{
		CommandListImpl::drawBegin(_backBufferIndex);
	}

	void CommandList::close()
	{
		CommandListImpl::close();
	}
}

CANDY_NAMESPACE_END
