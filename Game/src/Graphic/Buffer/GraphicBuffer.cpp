#include "GraphicBuffer.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Buffer::startupRenderTarget(const Device& _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height)
	{
		BufferImpl::startupRenderTarget(_device.getDevice(), _textureFormat, _width, _height);
	}

	void Buffer::startupBackBuffer(const SwapChain& _swapChain, const s32 _backBufferIndex)
	{
		BufferImpl::startupBackBuffer(_swapChain.getSwapChain(), _backBufferIndex);
	}

	void Buffer::cleanup()
	{
		BufferImpl::cleanup();
	}

	void Buffer::translationBarrier(const CommandList& _commandList, const BARRIER_STATE _barrierState)
	{
		BufferImpl::translationBarrier(_commandList.getCommandList(), _barrierState);
	}
}

CANDY_NAMESPACE_END
