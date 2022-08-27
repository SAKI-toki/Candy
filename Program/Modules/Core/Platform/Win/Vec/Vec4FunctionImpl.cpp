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
}

Vec4 VecSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return Vec4{ _mm_setr_ps(_x, _y, _z, _w) };
}
Vec4 VecSetZeroImpl()
{
	return Vec4{ Impl::Zero128 };
}

Vec4 VecAddImpl(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ _mm_add_ps(_v1.m128, _v2.m128) };
}
Vec4 VecSubImpl(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ _mm_sub_ps(_v1.m128, _v2.m128) };
}
Vec4 VecMulImpl(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ _mm_mul_ps(_v1.m128, _v2.m128) };
}
Vec4 VecDivImpl(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ _mm_div_ps(_v1.m128, _v2.m128) };
}

// 内積の実装部
f32 VecDotImpl(const Vec4& _v1, const Vec4& _v2)
{
	// SIMD計算の方が遅い
	return _v1.x * _v2.x + _v1.y * _v2.y + _v1.z * _v2.z;
}

// 外積の実装部
Vec4 VecCrossImpl(const Vec4& _v1, const Vec4& _v2)
{
	__m128 result1, result2, temp1, temp2;
	temp1 = _mm_shuffle_ps(_v1.m128, _v1.m128, CANDY_MM_SHUFFLE(1, 2, 0, 3));
	temp2 = _mm_shuffle_ps(_v2.m128, _v2.m128, CANDY_MM_SHUFFLE(2, 0, 1, 3));
	result1 = _mm_mul_ps(temp1, temp2);
	temp1 = _mm_shuffle_ps(_v1.m128, _v1.m128, CANDY_MM_SHUFFLE(2, 0, 1, 3));
	temp2 = _mm_shuffle_ps(_v2.m128, _v2.m128, CANDY_MM_SHUFFLE(1, 2, 0, 3));
	result2 = _mm_mul_ps(temp1, temp2);
	return Vec4{ _mm_sub_ps(result1, result2) };
}

f32 VecMagImpl(const Vec4& _v)
{
	return std::sqrtf(VecMagSqrImpl(_v));
}

f32 VecMagSqrImpl(const Vec4& _v)
{
	return VecDotImpl(_v, _v);
}

f32 VecDistImpl(const Vec4& _v1, const Vec4& _v2)
{
	return std::sqrtf(VecDistSqrImpl(_v1, _v2));
}

f32 VecDistSqrImpl(const Vec4& _v1, const Vec4& _v2)
{
	const auto v = _v2 - _v1;
	return VecDotImpl(v, v);
}

Vec4 VecNormalizeImpl(const Vec4& _v)
{
	const f32 mag = VecMagImpl(_v);
	if (mag <= 0.0f)return UpVector;
	const f32 rcp = 1.0f / mag;
	const __m128 v = _mm_set_ps(1.0f, rcp, rcp, rcp);
	return Vec4{ _mm_mul_ps(_v.m128, v) };
}

CANDY_CORE_NAMESPACE_END
