#ifndef CANDY_GRAPHIC_VIEWPORT_H
#define CANDY_GRAPHIC_VIEWPORT_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Viewport/GraphicViewportImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Viewport : public Impl::ViewportImpl
	{
	public:
		void set(const f32 _topLeftX, const f32 _topLeftY, const f32 _width,
			const f32 _height, const f32 _minDepth, const f32 _maxDepth);
		void set(const Rect& _rect, const f32 _minDepth, const f32 _maxDepth);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_VIEWPORT_H
