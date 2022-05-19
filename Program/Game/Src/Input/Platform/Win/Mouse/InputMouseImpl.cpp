#include "InputMouseImpl.h"
#include <Hardware/Platform/Win/HardwareImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	Vec4 MouseImpl::getScreenPos()const
	{
		POINT point;
		if (!::GetCursorPos(&point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}

	Vec4 MouseImpl::toClientPos(const Vec4 _screenPos)const
	{
		POINT point{ static_cast<s32>(_screenPos.m_f32.x), static_cast<s32>(_screenPos.m_f32.y) };
		if (!::ScreenToClient(Hardware::Impl::GetHwnd(), &point))return ZeroVector;
		return Vec4{ static_cast<f32>(point.x), static_cast<f32>(point.y), 0.0f };
	}
}

CANDY_NAMESPACE_END
