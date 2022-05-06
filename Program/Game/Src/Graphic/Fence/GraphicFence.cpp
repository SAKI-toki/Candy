#include "GraphicFence.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Fence::startup(const Device& _device)
	{
		FenceImpl::startup(_device.getDevice());
	}

	void Fence::cleanup()
	{
		FenceImpl::cleanup();
	}

	void Fence::signalFromCpu(const u64 _value)
	{
		FenceImpl::signalFromCpu(_value);
	}

	void Fence::signalFromGpu(const CommandQueue& _commandQueue, const u64 _value)
	{
		FenceImpl::signalFromGpu(_commandQueue.getCommandQueue(), _value);
	}

	void Fence::waitCpu(const u64 _value)
	{
		FenceImpl::waitCpu(_value);
	}

	void Fence::waitGpu(const CommandQueue& _commandQueue, const u64 _value)
	{
		FenceImpl::waitGpu(_commandQueue.getCommandQueue(), _value);
	}

	u64 Fence::getCompletedValue()
	{
		return FenceImpl::getCompletedValue();
	}
}

CANDY_NAMESPACE_END
