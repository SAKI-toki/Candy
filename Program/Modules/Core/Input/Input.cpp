/*****************************************************************//**
 * \file   Input.cpp
 * \brief  入力
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Input.h"
#include "Keyboard/InputKeyboard.h"
#include "Mouse/InputMouse.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Input
{
	Keyboard m_Keyboard;
	Mouse m_Mouse;
}

void Input::Startup()
{
	m_Keyboard.startup();
	m_Mouse.startup();
}

void Input::Cleanup()
{
	m_Keyboard.cleanup();
	m_Mouse.cleanup();
}

void Input::Update()
{
	m_Keyboard.update();
	m_Mouse.update();
}

bool Input::IsKeyTrigger(const u8 _key) { return m_Keyboard.isTrigger(_key); }
bool Input::IsKeyOn(const u8 _key)		{ return m_Keyboard.isOn(_key); }
bool Input::IsKeyRelease(const u8 _key) { return m_Keyboard.isRelease(_key); }
bool Input::IsKeyRepeat(const u8 _key)	{ return m_Keyboard.isRepeat(_key); }

Vec4 Input::GetScreenMousePos()		{ return m_Mouse.getScreenPos(); }
Vec4 Input::GetClientMousePos()		{ return m_Mouse.getClientPos(); }
Vec4 Input::GetPrevScreenMousePos()	{ return m_Mouse.getPrevScreenPos(); }
Vec4 Input::GetPrevClientMousePos() { return m_Mouse.getPrevClientPos(); }

CANDY_CORE_NAMESPACE_END
