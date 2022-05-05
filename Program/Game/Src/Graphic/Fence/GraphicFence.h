#ifndef CANDY_GRAPHIC_FENCE_H
#define CANDY_GRAPHIC_FENCE_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Fence/GraphicFenceImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Fence : public FenceImpl
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
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_FENCE_H
