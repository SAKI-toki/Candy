#ifndef CANDY_INPUT_KEYBOARD_IMPL_H
#define CANDY_INPUT_KEYBOARD_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	class KeyboardImpl
	{
	protected:
		void GetKeyboardState(bool(&_isOnKey)[256]);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_KEYBOARD_IMPL_H
