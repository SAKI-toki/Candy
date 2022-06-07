#ifndef CANDY_GRAPHIC_SWAP_CHAIN_H
#define CANDY_GRAPHIC_SWAP_CHAIN_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandQueue/GraphicCommandQueue.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/SwapChain/GraphicSwapChainImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class SwapChain : public Impl::SwapChainImpl
	{
	public:
		void startup(const Device& _device, const CommandQueue& _commandQueue,
			const GRAPHIC_FORMAT _graphicFormat, const s32 _backBufferCount, const s32 _width, const s32 _height);
		void cleanup();

		void present(const s32 _syncInterval);
		s32 getBackBufferIndex();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_SWAP_CHAIN_H
