#include "GraphicBackBuffer.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void BackBuffer::startup(const SwapChain& _swapChain, const s32 _backBufferIndex)
	{
		BackBufferImpl::startup(_swapChain.getSwapChain(), _backBufferIndex);
	}

	void BackBuffer::cleanup()
	{
		BackBufferImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
