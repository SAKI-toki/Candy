#include "GraphicBackBufferImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void BackBufferImpl::startup(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex)
	{
		_swapChain->GetBuffer(_backBufferIndex, IID_PPV_ARGS(getBufferAddress()));
	}

	void BackBufferImpl::cleanup()
	{
		BufferImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
