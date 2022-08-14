/*****************************************************************//**
 * \file   Vec4Impl.cpp
 * \brief  Vector4の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4Impl.h"

CANDY_CORE_NAMESPACE_BEGIN

Vec4Impl::Vec4Impl()
{
	set(0.0f, 0.0f, 0.0f);
}
Vec4Impl::Vec4Impl(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	set(_x, _y, _z, _w);
}
Vec4Impl::Vec4Impl(const __m128 _v)
{
	m128 = _v;
}

Vec4Impl& Vec4Impl::set(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	m128 = _mm_setr_ps(_x, _y, _z, _w);
	return *this;
}
Vec4Impl& Vec4Impl::setZero()
{
	return set(0.0f, 0.0f, 0.0f, 1.0f);
}

Vec4Impl Vec4Impl::getXY()const
{
	return Vec4Impl(x, y, 0.0f);
}

Vec4Impl Vec4Impl::operator+(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_add_ps(m128, _other.m128);
	v.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator-(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_sub_ps(m128, _other.m128);
	v.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator*(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_mul_ps(m128, _other.m128);
	v.w = 1.0f;
	return v;
}
Vec4Impl Vec4Impl::operator/(const Vec4Impl& _other)const
{
	Vec4Impl v = _mm_div_ps(m128, _other.m128);
	v.w = 1.0f;
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

CANDY_CORE_NAMESPACE_END
