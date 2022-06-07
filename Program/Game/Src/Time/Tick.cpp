/*****************************************************************//**
 * \file   Tick.cpp
 * \brief  ティック
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#include "Tick.h"

CANDY_NAMESPACE_BEGIN

Tick::Tick(const TickImpl& _other) : TickImpl{ _other } {}
Tick::Tick(TickImpl&& _other)noexcept :TickImpl{ std::move(_other) } {}
// 秒
f32 Tick::toSec()const
{
	return TickImpl::toSec();
}
// ミリ秒
f32 Tick::toMilliSec()const
{
	return TickImpl::toMilliSec();
}
// マイクロ秒
f32 Tick::toMicroSec()const
{
	return TickImpl::toMicroSec();
}

// 加減関数群
Tick Tick::operator+(const Tick& _other)const
{
	return TickImpl::operator+(_other);
}
Tick& Tick::operator+=(const Tick& _other)
{
	return *this = operator+(_other);
}
Tick Tick::operator-(const Tick& _other)const
{
	return TickImpl::operator-(_other);
}
Tick& Tick::operator-=(const Tick& _other)
{
	return *this = operator-(_other);
}

CANDY_NAMESPACE_END
