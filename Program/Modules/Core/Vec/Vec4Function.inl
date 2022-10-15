/*****************************************************************//**
 * \file   Vec4Function.inl
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_INL
#define CANDY_CORE_VEC4_FUNCTION_INL

#include "Vec4Function.h"

CANDY_NAMESPACE_BEGIN

template<u32 MM>
inline Vec4 VecPermute(const Vec4& _v)
{
	return core::VecPermuteImpl<MM>(_v.r);
}

template<u32 MM>
inline Vec4 VecShuffle(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecShuffleImpl<MM>(_v1.r, _v2.r);
}

CANDY_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_INL
