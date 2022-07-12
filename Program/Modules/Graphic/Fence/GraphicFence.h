#ifndef CANDY_GRAPHIC_FENCE_H
#define CANDY_GRAPHIC_FENCE_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Fence/GraphicFenceImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device;
class CommandQueue;

class Fence : public impl::FenceImpl
{
public:
	void startup(const Device& _device);
	void cleanup();

	void signalFromCpu(const u64 _value);
	void signalFromGpu(const CommandQueue& _commandQueue, const u64 _value);
	void waitCpu(const u64 _value);
	void waitGpu(const CommandQueue& _commandQueue, const u64 _value);
	u64 getCompletedValue();
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_FENCE_H
