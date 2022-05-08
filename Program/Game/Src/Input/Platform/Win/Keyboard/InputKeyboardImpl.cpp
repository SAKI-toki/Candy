#include "InputKeyboardImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	bool KeyboardImpl::GetKeyboardState(u8(&_keyInfos)[256])
	{
		return ::GetKeyboardState(_keyInfos);
	}
}

CANDY_NAMESPACE_END
