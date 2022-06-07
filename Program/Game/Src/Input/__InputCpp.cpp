/*****************************************************************//**
 * \file   __InputCpp.cpp
 * \brief  ���͊֘A��cpp�t�@�C������
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Input.cpp"
#include "Keyboard/InputKeyboard.cpp"
#include "Mouse/InputMouse.cpp"

#if PLATFORM_WIN
#include "Platform/Win/Keyboard/InputKeyboardImpl.cpp"
#include "Platform/Win/Mouse/InputMouseImpl.cpp"
#endif // PLATFORM_WIN
