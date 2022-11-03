/*****************************************************************//**
 * \file   Vec4FunctionImpl.inl
 * \brief  Vector4関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_IMPL_INL
#define CANDY_CORE_VEC4_FUNCTION_IMPL_INL

#include "Vec4FunctionImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
inline vector_type VecPermuteImpl(const vector_type _v)
{
	return VecShuffleImpl<FP1, FP2, FP3, FP4>(_v, _v);
}

template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
inline vector_type VecShuffleImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_shuffle_ps(_v1, _v2, CANDY_MM_SHUFFLE(FP1, FP2, FP3, FP4));
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_IMPL_INL
