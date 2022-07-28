/*****************************************************************//**
 * \file   InputMouseImpl.cpp
 * \brief  マウス入力の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputMouseImpl.h"
#include <Core/Platform/Win/Hardware/HardwareImpl.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Input::Impl
{
	// PC画面上の位置取得
	Vec4 MouseImpl::getScreenPos()const
	{
		POINT point;
		if (!::GetCursorPos(&point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}

	// PC画面上の位置からアプリ画面上の位置に変換
	Vec4 MouseImpl::toClientPos(const Vec4 _screenPos)const
	{
		POINT point{ static_cast<s32>(_screenPos.x), static_cast<s32>(_screenPos.y) };
		if (!::ScreenToClient(Hardware::Impl::GetHwnd(), &point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}
}

CANDY_CORE_NAMESPACE_END
