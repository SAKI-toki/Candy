#ifndef CANDY_GRAPHIC_RENDER_TARGET_IMPL_H
#define CANDY_GRAPHIC_RENDER_TARGET_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class RenderTargetImpl : public BufferImpl
	{
	public:
		void startup(ID3D12Device* const _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_RENDER_TARGET_IMPL_H
