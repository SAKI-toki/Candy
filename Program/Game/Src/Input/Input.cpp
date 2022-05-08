#include "Input.h"
#include "Keyboard/InputKeyboard.h"

CANDY_NAMESPACE_BEGIN

namespace Input
{
	Keyboard m_Keyboard;
}

void Input::Startup()
{
	m_Keyboard.startup();
}

void Input::Cleanup()
{
	m_Keyboard.cleanup();
}

void Input::Update()
{
	m_Keyboard.update();
}

bool Input::IsKeyTrigger(const u8 _key) { return m_Keyboard.isTrigger(_key); }
bool Input::IsKeyOn(const u8 _key)		{ return m_Keyboard.isOn(_key); }
bool Input::IsKeyRelease(const u8 _key) { return m_Keyboard.isRelease(_key); }
bool Input::IsKeyRepeat(const u8 _key)	{ return m_Keyboard.isRepeat(_key); }

CANDY_NAMESPACE_END
