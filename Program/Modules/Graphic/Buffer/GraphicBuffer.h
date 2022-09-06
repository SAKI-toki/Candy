#ifndef CANDY_GRAPHIC_BUFFER_H
#define CANDY_GRAPHIC_BUFFER_H

#include <Graphic/GraphicInclude.h>

#include "StartupInfo/GraphicBufferStartupInfo.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device;
class SwapChain;
class CommandList;

class Buffer : public impl::BufferImpl
{
public:
	void startup(const Device& _device, const BufferStartupInfo& _startupInfo);
	void startupBackBuffer(const SwapChain& _swapChain, const s32 _backBufferIndex);
	void cleanup();

	void translationBarrier(const CommandList& _commandList, 
		const types::BARRIER_STATE _prevBarrierState, const types::BARRIER_STATE _nextBarrierState);

	void store(const std::byte* const _buf, const u64 _size, const u64 _offset);

	void setName(const std::string_view _name);
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_H
