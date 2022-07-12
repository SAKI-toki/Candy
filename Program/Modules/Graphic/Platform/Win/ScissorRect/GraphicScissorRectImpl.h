#ifndef CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H
#define CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class ScissorRectImpl
	{
	protected:
		void set(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);

	public:
		const D3D12_RECT* getScissorRect()const { return &m_ScissorRect; }

	private:
		D3D12_RECT m_ScissorRect;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SCISSOR_RECT_IMPL_H
