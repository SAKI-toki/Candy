#include "TimeImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Time::Impl
{
	LARGE_INTEGER m_Frequency{};

	f32 ToImpl(const LARGE_INTEGER _value, const f64 _mul);
}

void Time::Impl::Startup()
{
	::QueryPerformanceFrequency(&m_Frequency);
}
void Time::Impl::Cleanup()
{

}

f32 Time::Impl::ToSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1.0);
}
f32 Time::Impl::ToMilliSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1000.0);
}
f32 Time::Impl::ToMicroSec(const LARGE_INTEGER _value)
{
	return ToImpl(_value, 1000000.0);
}

f32 Time::Impl::ToImpl(const LARGE_INTEGER _value, const f64 _mul)
{
	return static_cast<f32>(static_cast<f64>(_value.QuadPart) / static_cast<f64>(m_Frequency.QuadPart) * _mul);
}

CANDY_NAMESPACE_END
