#include "GraphicViewportImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void ViewportImpl::set(const f32 _topLeftX, const f32 _topLeftY, const f32 _width,
		const f32 _height, const f32 _minDepth, const f32 _maxDepth)
	{
		m_Viewport.TopLeftX = _topLeftX;
		m_Viewport.TopLeftX = _topLeftY;
		m_Viewport.Width = _width;
		m_Viewport.Height = _height;
		m_Viewport.MinDepth = _minDepth;
		m_Viewport.MaxDepth = _maxDepth;
	}
}

CANDY_NAMESPACE_END
