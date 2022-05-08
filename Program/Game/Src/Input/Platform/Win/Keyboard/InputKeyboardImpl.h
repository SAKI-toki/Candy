#ifndef CANDY_INPUT_KEYBOARD_IMPL_H
#define CANDY_INPUT_KEYBOARD_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	class KeyboardImpl
	{
	protected:
		bool GetKeyboardState(u8(&_keyInfos)[256]);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_KEYBOARD_IMPL_H
