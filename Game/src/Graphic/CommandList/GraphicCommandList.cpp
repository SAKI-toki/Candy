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

	void CommandList::setViewport(const Viewport& _viewport)
	{
		CommandListImpl::setViewport(_viewport.getViewport());
	}

	void CommandList::setScissorRect(const ScissorRect& _scissorRect)
	{
		CommandListImpl::setScissorRect(_scissorRect.getScissorRect());
	}

	void CommandList::setRenderTargets(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const s32 _renderTargetCount)
	{
		CommandListImpl::setRenderTargets(_rtDescriptorCpuHandle.getHandle(), _renderTargetCount, nullptr);
	}

	void CommandList::setRenderTargetsDepthStencil(const DescriptorCpuHandle& _rtDescriptorCpuHandle,
		const s32 _renderTargetCount, const DescriptorCpuHandle& _dsDescriptorCpuHandle)
	{
		CommandListImpl::setRenderTargets(_rtDescriptorCpuHandle.getHandle(), _renderTargetCount, _dsDescriptorCpuHandle.getHandle());
	}
}

CANDY_NAMESPACE_END
