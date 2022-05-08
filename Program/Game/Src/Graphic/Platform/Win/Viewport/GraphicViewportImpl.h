#ifndef CANDY_GRAPHIC_VIEWPORT_IMPL_H
#define CANDY_GRAPHIC_VIEWPORT_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class ViewportImpl
	{
	protected:
		void set(const f32 _topLeftX, const f32 _topLeftY, const f32 _width,
			const f32 _height, const f32 _minDepth, const f32 _maxDepth);

	public:
		const D3D12_VIEWPORT* getViewport()const { return &m_Viewport; }

	private:
		D3D12_VIEWPORT m_Viewport;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_VIEWPORT_IMPL_H
