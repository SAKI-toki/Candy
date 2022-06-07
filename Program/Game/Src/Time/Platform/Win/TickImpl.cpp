#include "TickImpl.h"
#include "TimeImpl.h"

CANDY_NAMESPACE_BEGIN

TickImpl::TickImpl()
{
	::QueryPerformanceCounter(&m_Value);
}

f32 TickImpl::toSec()const
{
	return Time::Impl::ToSec(m_Value);
}
f32 TickImpl::toMilliSec()const
{
	return Time::Impl::ToMilliSec(m_Value);
}
f32 TickImpl::toMicroSec()const
{
	return Time::Impl::ToMicroSec(m_Value);
}

TickImpl TickImpl::operator+(const TickImpl& _other)const
{
	TickImpl tickImpl;
	tickImpl.m_Value.QuadPart = m_Value.QuadPart + _other.m_Value.QuadPart;
	return tickImpl;
}
TickImpl& TickImpl::operator+=(const TickImpl& _other)
{
	m_Value.QuadPart += _other.m_Value.QuadPart;
	return *this;
}
TickImpl TickImpl::operator-(const TickImpl& _other)const
{
	TickImpl tickImpl;
	tickImpl.m_Value.QuadPart = m_Value.QuadPart - _other.m_Value.QuadPart;
	return tickImpl;
}
TickImpl& TickImpl::operator-=(const TickImpl& _other)
{
	m_Value.QuadPart -= _other.m_Value.QuadPart;
	return *this;
}

CANDY_NAMESPACE_END
