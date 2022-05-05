#ifndef CANDY_RECT_H
#define CANDY_RECT_H

CANDY_NAMESPACE_BEGIN

struct alignas(16) Rect
{
	Rect();
	Rect(const f32 _x, const f32 _y, const f32 _width, const f32 _height);

	Rect& setSize(const f32 _x, const f32 _y, const f32 _width, const f32 _height);
	Rect& setPos(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);

	f32 getRight()const;
	f32 getBottom()const;

	f32 m_X;
	f32 m_Y;
	f32 m_Width;
	f32 m_Height;
};

CANDY_NAMESPACE_END

#include "Rect.inl"

#endif // CANDY_RECT_H
