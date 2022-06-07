#ifndef CANDY_VEC4_IMPL_H
#define CANDY_VEC4_IMPL_H

CANDY_NAMESPACE_BEGIN

struct alignas(16) Vec4Impl
{
	Vec4Impl();
	Vec4Impl(const f32 _x, const f32 _y, const f32 _z, const f32 _w = 1.0f);
	Vec4Impl(const __m128 _v);

	Vec4Impl& set(const f32 _x, const f32 _y, const f32 _z, const f32 _w = 1.0f);
	Vec4Impl& setZero();

	Vec4Impl operator+(const Vec4Impl&)const;
	Vec4Impl operator-(const Vec4Impl&)const;
	Vec4Impl operator*(const Vec4Impl&)const;
	Vec4Impl operator/(const Vec4Impl&)const;
	Vec4Impl operator*(const f32&)const;
	Vec4Impl operator/(const f32&)const;
	Vec4Impl& operator+=(const Vec4Impl&);
	Vec4Impl& operator-=(const Vec4Impl&);
	Vec4Impl& operator*=(const f32&);
	Vec4Impl& operator/=(const f32&);

	union
	{
		struct
		{
			f32 x, y, z, w;
		}m_f32;
		struct
		{
			f32 r, g, b, a;
		}m_f32Col;
		
		f32 m_f32Array[4];

		__m128 m_m128;
	};
};

CANDY_NAMESPACE_END

#include "Vec4Impl.inl"

#endif // CANDY_VEC4_IMPL_H
