#ifndef CANDY_GRAPHIC_SWAP_CHAIN_H
#define CANDY_GRAPHIC_SWAP_CHAIN_H

#include <Graphic/GraphicInclude.h>

#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/SwapChain/GraphicSwapChainImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class SwapChain : public impl::SwapChainImpl
{
public:
	void startup(const Device& _device, const CommandQueue& _commandQueue, const types::GRAPHIC_FORMAT _graphicFormat, 
		const s32 _backBufferCount, const s32 _width, const s32 _height);
	void cleanup();

	void present(const s32 _syncInterval);
	s32 getBackBufferIndex();
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SWAP_CHAIN_H
