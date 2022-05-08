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
		void startup();
		void cleanup();

		void update();

		void reset();

		bool isTrigger(const u32 _key)const;
		bool isOn(const u32 _key)const;
		bool isRelease(const u32 _key)const;
		bool isRepeat(const u32 _key)const;

	private:
		u32 m_Trigger[8]{};
		u32 m_On[8]{};
		u32 m_Release[8]{};
		u32 m_Repeat[8]{};

		void setKey(u32(&_keyStates)[8], const u32 _key, const bool _isOn);
		bool isKey(const u32(&_keyStates)[8], const u32 _key)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_KEYBOARD_H
