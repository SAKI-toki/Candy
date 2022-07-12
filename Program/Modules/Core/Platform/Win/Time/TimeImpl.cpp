/*****************************************************************//**
 * \file   TimeImpl.cpp
 * \brief  時間の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#include "TimeImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Time::Impl
{
	LARGE_INTEGER m_Frequency{};

	f32 ToImpl(const LARGE_INTEGER _value, const f64 _mul);
}

// 初期化
void Time::Impl::Startup()
{
	::QueryPerformanceFrequency(&m_Frequency);
}
// 破棄
void Time::Impl::Cleanup()
{

}

// 秒
f32 Time::Impl::ToSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1.0);
}
// ミリ秒
f32 Time::Impl::ToMilliSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1000.0);
}
// マイクロ秒
f32 Time::Impl::ToMicroSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1000000.0);
}

f32 Time::Impl::ToImpl(const LARGE_INTEGER _value, const f64 _mul)
{
	return static_cast<f32>(static_cast<f64>(_value.QuadPart) / static_cast<f64>(m_Frequency.QuadPart) * _mul);
}

CANDY_CORE_NAMESPACE_END
