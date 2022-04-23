#include "GraphicRenderTarget.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void RenderTarget::startup(const Device& _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height)
	{
		RenderTargetImpl::startup(_device.getDevice(), _textureFormat, _width, _height);
	}

	void RenderTarget::cleanup()
	{
		RenderTargetImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
