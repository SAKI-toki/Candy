#include "GraphicRenderTargetImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void RenderTargetImpl::startup(ID3D12Device* const _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height)
	{
		BufferImpl::startupRenderTarget(_device, _textureFormat, _width, _height);
	}

	void RenderTargetImpl::cleanup()
	{
		BufferImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
