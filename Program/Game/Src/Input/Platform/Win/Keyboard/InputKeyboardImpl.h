/*****************************************************************//**
 * \file   InputKeyboardImpl.h
 * \brief  キーボード入力の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_KEYBOARD_IMPL_H
#define CANDY_INPUT_KEYBOARD_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	class KeyboardImpl
	{
	protected:
		// キーボードの入力状態を取得
		void GetKeyboardState(bool(&_isOnKey)[256]);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_KEYBOARD_IMPL_H
