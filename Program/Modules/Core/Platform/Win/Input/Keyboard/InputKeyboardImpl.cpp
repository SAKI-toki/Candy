/*****************************************************************//**
 * \file   InputKeyboardImpl.cpp
 * \brief  キーボード入力の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputKeyboardImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Input::Impl
{
	// キーボードの入力状態を取得
	void KeyboardImpl::GetKeyboardState(bool(&_isOnKey)[256])
	{
		for (s32 i = 0; i < 256; ++i)
		{
			_isOnKey[i] = ::GetAsyncKeyState(i) & 0x8000;
		}
	}
}

CANDY_CORE_NAMESPACE_END
