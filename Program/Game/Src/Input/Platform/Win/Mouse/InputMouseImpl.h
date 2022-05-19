#ifndef CANDY_INPUT_MOUSE_IMPL_H
#define CANDY_INPUT_MOUSE_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	class MouseImpl
	{
	protected:
		Vec4 getScreenPos()const;
		Vec4 toClientPos(const Vec4 _screenPos)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_MOUSE_IMPL_H
