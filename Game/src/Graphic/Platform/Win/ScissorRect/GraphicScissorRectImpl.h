#ifndef CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H
#define CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class ScissorRectImpl
	{
	public:
		void set(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);
		void set(const Rect& _rect);

		const D3D12_RECT* getScissorRect()const { return &m_ScissorRect; }

	private:
		D3D12_RECT m_ScissorRect;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H
