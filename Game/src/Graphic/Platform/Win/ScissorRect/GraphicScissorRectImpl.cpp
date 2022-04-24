#include "GraphicScissorRectImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void ScissorRectImpl::set(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom)
	{
		m_ScissorRect.left = static_cast<LONG>(_left);
		m_ScissorRect.top = static_cast<LONG>(_top);
		m_ScissorRect.right = static_cast<LONG>(_right);
		m_ScissorRect.bottom = static_cast<LONG>(_bottom);
	}
}

CANDY_NAMESPACE_END
