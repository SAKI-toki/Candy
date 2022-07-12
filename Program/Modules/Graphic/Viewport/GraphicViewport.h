#ifndef CANDY_GRAPHIC_VIEWPORT_H
#define CANDY_GRAPHIC_VIEWPORT_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Viewport/GraphicViewportImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Viewport : public impl::ViewportImpl
{
public:
	void set(const f32 _topLeftX, const f32 _topLeftY, const f32 _width,
		const f32 _height, const f32 _minDepth, const f32 _maxDepth);
	void set(const Rect& _rect, const f32 _minDepth, const f32 _maxDepth);
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_VIEWPORT_H
