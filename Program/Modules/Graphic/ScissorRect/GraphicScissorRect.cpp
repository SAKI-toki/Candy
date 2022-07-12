#include "GraphicScissorRect.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void ScissorRect::set(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom)
{
	ScissorRectImpl::set(_left, _top, _right, _bottom);
}

void ScissorRect::set(const Rect& _rect)
{
	set(_rect.m_X, _rect.m_Y, _rect.getRight(), _rect.getBottom());
}

CANDY_GRAPHIC_NAMESPACE_END
