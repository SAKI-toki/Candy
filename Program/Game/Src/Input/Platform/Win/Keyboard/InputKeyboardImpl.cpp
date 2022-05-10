#include "InputKeyboardImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	void KeyboardImpl::GetKeyboardState(bool(&_isOnKey)[256])
	{
		for (s32 i = 0; i < 256; ++i)
		{
			_isOnKey[i] = ::GetAsyncKeyState(i) & 0x8000;
		}
	}
}

CANDY_NAMESPACE_END
