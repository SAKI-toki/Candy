#include "Vec4Impl.h"

CANDY_NAMESPACE_BEGIN

Vec4Impl::Vec4Impl()
{
}
Vec4Impl::Vec4Impl(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	set(_x, _y, _z, _w);
}
Vec4Impl::Vec4Impl(const __m128 _v)
{
	m_m128 = _v;
}

Vec4Impl& Vec4Impl::set(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	m_m128 = _mm_set_ps(_w, _z, _y, _x);
	return *this;
}
Vec4Impl& Vec4Impl::setZero()
{
	return set(0.0f, 0.0f, 0.0f);
}

Vec4Impl Vec4Impl::operator+(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_add_ps(m_m128, _other.m_m128);
	v.m_f32.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator-(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_sub_ps(m_m128, _other.m_m128);
	v.m_f32.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator*(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_mul_ps(m_m128, _other.m_m128);
	v.m_f32.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator/(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_div_ps(m_m128, _other.m_m128);
	v.m_f32.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator*(const f32& _other)const
{
	return *this * (Vec4Impl{ _other, _other, _other });
}
Vec4Impl Vec4Impl::operator/(const f32& _other)const
{
	return *this / (Vec4Impl{ _other, _other, _other });
}
Vec4Impl& Vec4Impl::operator+=(const Vec4Impl& _other)
{
	*this = *this + _other;
	return *this;
}
Vec4Impl& Vec4Impl::operator-=(const Vec4Impl& _other)
{
	*this = *this - _other;
	return *this;
}
Vec4Impl& Vec4Impl::operator*=(const f32& _other)
{
	*this = *this * _other;
	return *this;
}
Vec4Impl& Vec4Impl::operator/=(const f32& _other)
{
	*this = *this / _other;
	return *this;
}

CANDY_NAMESPACE_END
