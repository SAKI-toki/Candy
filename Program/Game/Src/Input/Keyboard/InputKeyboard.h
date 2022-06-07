/*****************************************************************//**
 * \file   InputKeyboard.h
 * \brief  キーボード入力
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_KEYBOARD_H
#define CANDY_INPUT_KEYBOARD_H

#if PLATFORM_WIN
#include <Input/Platform/Win/Keyboard/InputKeyboardImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Input
{
	class Keyboard : public Impl::KeyboardImpl
	{
	public:
		// 初期化
		void startup();
		// 破棄
		void cleanup();
		// 更新
		void update();

		// リセット
		void reset();

		// 入力開始判定
		bool isTrigger(const u32 _key)const;
		// 入力判定
		bool isOn(const u32 _key)const;
		// 入力終了判定
		bool isRelease(const u32 _key)const;
		// 入力判定(一定間隔)
		bool isRepeat(const u32 _key)const;

	private:
		u32 m_Trigger[8]{};
		u32 m_On[8]{};
		u32 m_Release[8]{};
		u32 m_Repeat[8]{};

		// キー情報のセット
		void setKey(u32(&_keyStates)[8], const u32 _key, const bool _isOn);
		// キー判定
		bool isKey(const u32(&_keyStates)[8], const u32 _key)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_KEYBOARD_H
