/*****************************************************************//**
 * \file   TickImpl.cpp
 * \brief  ティックの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#include "TickImpl.h"
#include "TimeImpl.h"

CANDY_NAMESPACE_BEGIN

TickImpl::TickImpl()
{
	::QueryPerformanceCounter(&m_Value);
}

// 秒
f32 TickImpl::toSec()const
{
	return Time::Impl::ToSec(m_Value);
}
// ミリ秒
f32 TickImpl::toMilliSec()const
{
	return Time::Impl::ToMilliSec(m_Value);
}
// マイクロ秒
f32 TickImpl::toMicroSec()const
{
	return Time::Impl::ToMicroSec(m_Value);
}

// 加減関数群
TickImpl TickImpl::operator+(const TickImpl& _other)const
{
	TickImpl tickImpl;
	tickImpl.m_Value.QuadPart = m_Value.QuadPart + _other.m_Value.QuadPart;
	return tickImpl;
}
TickImpl TickImpl::operator-(const TickImpl& _other)const
{
	TickImpl tickImpl;
	tickImpl.m_Value.QuadPart = m_Value.QuadPart - _other.m_Value.QuadPart;
	return tickImpl;
}

CANDY_NAMESPACE_END
