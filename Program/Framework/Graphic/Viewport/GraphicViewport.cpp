#include "GraphicViewport.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Viewport::set(const f32 _topLeftX, const f32 _topLeftY, const f32 _width,
		const f32 _height, const f32 _minDepth, const f32 _maxDepth)
	{
		ViewportImpl::set(_topLeftX, _topLeftY, _width, _height, _minDepth, _maxDepth);
	}

	void Viewport::set(const Rect& _rect, const f32 _minDepth, const f32 _maxDepth)
	{
		set(_rect.m_X, _rect.m_Y, _rect.m_Width, _rect.m_Height, _minDepth, _maxDepth);
	}
}

CANDY_NAMESPACE_END
