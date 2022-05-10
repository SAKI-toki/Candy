#include "InputKeyboard.h"

CANDY_NAMESPACE_BEGIN

namespace Input
{
	void Keyboard::startup()
	{
		reset();
	}

	void Keyboard::cleanup()
	{

	}

	void Keyboard::update()
	{
		bool isOnKey[256];
		GetKeyboardState(isOnKey);
		for (u32 i = 0; i < 256; ++i)
		{
			bool isPrevOn = isOn(i);
			bool isNextOn = isOnKey[i];
			if (isPrevOn != isNextOn)
			{
				if (isNextOn)setKey(m_Trigger, i, true);
				if (isPrevOn)setKey(m_Release, i, true);
			}
			else
			{
				setKey(m_Trigger, i, false);
				setKey(m_Release, i, false);
			}
			setKey(m_On, i, isNextOn);
		}
	}

	void Keyboard::reset()
	{
		for (auto& trig : m_Trigger)trig = 0;
		for (auto& on : m_On)on = 0;
		for (auto& release : m_Release)release = 0;
		for (auto& repeat : m_Repeat)repeat = 0;
	}

	void Keyboard::setKey(u32(&_keyStates)[8], const u32 _key, const bool _isOn)
	{
		if (_isOn)
		{
			_keyStates[_key / 32] |= (1 << _key % 32);
		}
		else
		{
			_keyStates[_key / 32] &= ~(1 << _key % 32);
		}
	}

	bool Keyboard::isKey(const u32(&_keyStates)[8], const u32 _key)const
	{
		return _keyStates[_key / 32] & (1 << _key % 32);
	}

	bool Keyboard::isTrigger(const u32 _key)const { return isKey(m_Trigger, _key); }
	bool Keyboard::isOn(const u32 _key)const { return isKey(m_On, _key); }
	bool Keyboard::isRelease(const u32 _key)const { return isKey(m_Release, _key); }
	bool Keyboard::isRepeat(const u32 _key)const { return isKey(m_Repeat, _key); }
}

CANDY_NAMESPACE_END
