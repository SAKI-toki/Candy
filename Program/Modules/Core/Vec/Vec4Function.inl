/*****************************************************************//**
 * \file   Vec4Function.inl
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_INL
#define CANDY_CORE_VEC4_FUNCTION_INL

#include "Vec4Function.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Vec/Vec4FunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
inline Vec4 VecPermute(const Vec4& _v)
{
	return core::VecPermuteImpl<FP1, FP2, FP3, FP4>(_v.r);
}

template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
inline Vec4 VecShuffle(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecShuffleImpl<FP1, FP2, FP3, FP4>(_v1.r, _v2.r);
}

CANDY_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_INL
