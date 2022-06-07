/*****************************************************************//**
 * \file   InputMouseImpl.cpp
 * \brief  �}�E�X���͂̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputMouseImpl.h"
#include <Hardware/Platform/Win/HardwareImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	// PC��ʏ�̈ʒu�擾
	Vec4 MouseImpl::getScreenPos()const
	{
		POINT point;
		if (!::GetCursorPos(&point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}

	// PC��ʏ�̈ʒu����A�v����ʏ�̈ʒu�ɕϊ�
	Vec4 MouseImpl::toClientPos(const Vec4 _screenPos)const
	{
		POINT point{ static_cast<s32>(_screenPos.m_f32.x), static_cast<s32>(_screenPos.m_f32.y) };
		if (!::ScreenToClient(Hardware::Impl::GetHwnd(), &point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}
}

CANDY_NAMESPACE_END
