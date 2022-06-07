#ifndef CANDY_GRAPHIC_SCISSOR_RECT_H
#define CANDY_GRAPHIC_SCISSOR_RECT_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/ScissorRect/GraphicScissorRectImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class ScissorRect : public Impl::ScissorRectImpl
	{
	public:
		void set(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);
		void set(const Rect& _rect);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_SCISSOR_RECT_H
