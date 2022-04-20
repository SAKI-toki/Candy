#include "GraphicSwapChain.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void SwapChain::startup(const Device& _device, const CommandQueue& _commandQueue,
		const TEXTURE_FORMAT _textureFormat, const s32 _frameCount, const s32 _width, const s32 _height)
	{
		SwapChainImpl::startup(_device.getFactory(), _commandQueue.getCommandQueue(),
			_textureFormat, _frameCount, _width, _height);
	}

	void SwapChain::cleanup()
	{
		SwapChainImpl::cleanup();
	}

	void SwapChain::present(const s32 _syncInterval)
	{
		SwapChainImpl::present(_syncInterval);
	}
}

CANDY_NAMESPACE_END
