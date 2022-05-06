#ifndef CANDY_GRAPHIC_BUFFER_H
#define CANDY_GRAPHIC_BUFFER_H

#include <Graphic/GraphicDef.h>
#include "StartupInfo/GraphicBufferStartupInfo.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Device;
	class SwapChain;
	class CommandList;

	class Buffer : public BufferImpl
	{
	public:
		void startup(const Device& _device, const BufferStartupInfo& _startupInfo);
		void startupBackBuffer(const SwapChain& _swapChain, const s32 _backBufferIndex);
		void cleanup();

		void translationBarrier(const CommandList& _commandList, const BARRIER_STATE _barrierState);

		void store(const std::byte* const _buf, const u64 _size, const u64 _offset);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_H
