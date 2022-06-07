/*****************************************************************//**
 * \file   InputKeyboardImpl.cpp
 * \brief  �L�[�{�[�h���͂̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputKeyboardImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	// �L�[�{�[�h�̓��͏�Ԃ��擾
	void KeyboardImpl::GetKeyboardState(bool(&_isOnKey)[256])
	{
		for (s32 i = 0; i < 256; ++i)
		{
			_isOnKey[i] = ::GetAsyncKeyState(i) & 0x8000;
		}
	}
}

CANDY_NAMESPACE_END
