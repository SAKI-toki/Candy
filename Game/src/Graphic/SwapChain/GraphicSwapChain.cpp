#include "GraphicSwapChain.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void SwapChain::startup(const Device& _device, const CommandQueue& _commandQueue,
		const TEXTURE_FORMAT _textureFormat, const s32 _backBufferCount, const s32 _width, const s32 _height)
	{
		SwapChainImpl::startup(_device.getFactory(), _commandQueue.getCommandQueue(),
			_textureFormat, _backBufferCount, _width, _height);
	}

	void SwapChain::cleanup()
	{
		SwapChainImpl::cleanup();
	}

	void SwapChain::present(const s32 _syncInterval)
	{
		SwapChainImpl::present(_syncInterval);
	}

	s32 SwapChain::getBackBufferIndex()
	{
		return SwapChainImpl::getBackBufferIndex();
	}
}

CANDY_NAMESPACE_END
