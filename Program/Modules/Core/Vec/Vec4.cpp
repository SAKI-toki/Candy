/*****************************************************************//**
 * \file   Vec4.cpp
 * \brief  Vector4
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4.h"

CANDY_NAMESPACE_BEGIN

Vec4::Vec4()
{
	set(0.0f, 0.0f, 0.0f);
}
Vec4::Vec4(const core::Vec4Impl& _v) : core::Vec4Impl{ _v }
{

}
Vec4::Vec4(core::Vec4Impl&& _v)noexcept : core::Vec4Impl{ std::move(_v) }
{

}
Vec4::Vec4(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	set(_x, _y, _z, _w);
}

Vec4& Vec4::set(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	*this = VecSet(_x, _y, _z, _w);
	return *this;
}
Vec4& Vec4::setZero()
{
	*this = VecSetZero();
	return *this;
}

Vec4 Vec4::getXY()const
{
	return Vec4{ x, y, 0.0f };
}

Vec4 Vec4::operator+(const Vec4& _other)const
{
	auto v = VecAdd(*this, _other);
	v.w = 1.0f;
	return v;
}
Vec4 Vec4::operator-(const Vec4& _other)const
{
	auto v = VecSub(*this, _other);
	v.w = 1.0f;
	return v;
}
Vec4 Vec4::operator*(const Vec4& _other)const
{
	auto v = VecMul(*this, _other);
	v.w = 1.0f;
	return v;
}
Vec4 Vec4::operator/(const Vec4& _other)const
{
	auto v = VecDiv(*this, _other);
	v.w = 1.0f;
	return v;
}
Vec4 Vec4::operator*(const f32& _other)const
{
	return *this * (Vec4{ _other, _other, _other });
}
Vec4 Vec4::operator/(const f32& _other)const
{
	return *this / (Vec4{ _other, _other, _other });
}
Vec4& Vec4::operator+=(const Vec4& _other)
{
	*this = *this + _other;
	return *this;
}
Vec4& Vec4::operator-=(const Vec4& _other)
{
	*this = *this - _other;
	return *this;
}
Vec4& Vec4::operator*=(const f32& _other)
{
	*this = *this * _other;
	return *this;
}
Vec4& Vec4::operator/=(const f32& _other)
{
	*this = *this / _other;
	return *this;
}
bool Vec4::operator==(const Vec4& _other)const
{
	return
		std::abs(x - _other.x) < std::numeric_limits<f32>::epsilon() &&
		std::abs(y - _other.y) < std::numeric_limits<f32>::epsilon() &&
		std::abs(z - _other.z) < std::numeric_limits<f32>::epsilon();
}
bool Vec4::operator!=(const Vec4& _other)const
{
	return !operator==(_other);
}

CANDY_NAMESPACE_END
