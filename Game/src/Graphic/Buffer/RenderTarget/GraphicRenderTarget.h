#ifndef CANDY_GRAPHIC_RENDER_TARGET_H
#define CANDY_GRAPHIC_RENDER_TARGET_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/RenderTarget/GraphicRenderTargetImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class RenderTarget : public RenderTargetImpl
	{
	public:
		void startup(const Device& _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_RENDER_TARGET_H
