/*****************************************************************//**
 * \file   Vec4FunctionImpl.cpp
 * \brief  Vector4関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4FunctionImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Impl
{
	__m128 Zero128 = _mm_setzero_ps();
	__m128 One128 = _mm_set_ps1(1.0f);

	f32 VecGet0(const __m128 _v)
	{
		return *(reinterpret_cast<const f32*>(&_v) + 0);
	}
	f32 VecGet1(const __m128 _v)
	{
		return *(reinterpret_cast<const f32*>(&_v) + 1);
	}
	f32 VecGet2(const __m128 _v)
	{
		return *(reinterpret_cast<const f32*>(&_v) + 2);
	}
	f32 VecGet3(const __m128 _v)
	{
		return *(reinterpret_cast<const f32*>(&_v) + 3);
	}

	__m128 VecDot128(const __m128 _v1, const __m128 _v2)
	{
		__m128 v, temp;
		v = _mm_mul_ps(_v1, _v2);
		temp = _mm_shuffle_ps(v, v, CANDY_MM_SHUFFLE(1, 2, 1, 2));
		v = _mm_add_ss(v, temp);
		temp = _mm_shuffle_ps(v, v, CANDY_MM_SHUFFLE(2, 2, 2, 2));
		v = _mm_add_ss(v, temp);
		return v;
	}

	__m128 VecDist128(const __m128 _v1, const __m128 _v2)
	{
		__m128 v = _mm_sub_ps(_v1, _v2);
		return VecDot128(v, v);
	}
}

// 内積の実装部
f32 VecDotImpl(const Vec4Impl _v1, const Vec4Impl _v2)
{
	__m128 result = Impl::VecDot128(_v1.m128, _v2.m128);
	return Impl::VecGet0(result);
}

// 外積の実装部
Vec4Impl VecCrossImpl(const Vec4Impl _v1, const Vec4Impl _v2)
{
	__m128 result1, result2, temp1, temp2;
	temp1 = _mm_shuffle_ps(_v1.m128, _v1.m128, CANDY_MM_SHUFFLE(1, 2, 0, 3));
	temp2 = _mm_shuffle_ps(_v2.m128, _v2.m128, CANDY_MM_SHUFFLE(2, 0, 1, 3));
	result1 = _mm_mul_ps(temp1, temp2);
	temp1 = _mm_shuffle_ps(_v1.m128, _v1.m128, CANDY_MM_SHUFFLE(2, 0, 1, 3));
	temp2 = _mm_shuffle_ps(_v2.m128, _v2.m128, CANDY_MM_SHUFFLE(1, 2, 0, 3));
	result2 = _mm_mul_ps(temp1, temp2);
	return Vec4Impl{ _mm_sub_ps(result1, result2) };
}

f32 VecMagImpl(const Vec4Impl _v)
{
	__m128 result = Impl::VecDot128(_v.m128, _v.m128);
	result = _mm_sqrt_ss(result);
	return Impl::VecGet0(result);
}

f32 VecMagSqrImpl(const Vec4Impl _v)
{
	return VecDotImpl(_v, _v);
}

f32 VecDistImpl(const Vec4Impl _v1, const Vec4Impl _v2)
{
	__m128 result = Impl::VecDist128(_v1.m128, _v2.m128);
	result = _mm_sqrt_ss(result);
	return Impl::VecGet0(result);
}

f32 VecDistSqrImpl(const Vec4Impl _v1, const Vec4Impl _v2)
{
	return VecDotImpl(_v1, _v2);
}

Vec4Impl VecNormalizeImpl(const Vec4Impl _v)
{
	f32 mag = VecMagImpl(_v);
	if (mag <= 0.0f)return UpVector;
	f32 rcp = 1.0f / mag;
	__m128 v = _mm_set_ps(1.0f, rcp, rcp, rcp);
	return Vec4Impl{ _mm_mul_ps(_v.m128, v) };
}

CANDY_CORE_NAMESPACE_END
