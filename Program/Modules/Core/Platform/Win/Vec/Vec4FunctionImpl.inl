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

template<u32 MM>
inline vector_type VecPermuteImpl(const vector_type _v)
{
	return VecShuffleImpl<MM>(_v, _v);
}

template<u32 MM>
inline vector_type VecShuffleImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_shuffle_ps(_v1, _v2, MM);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_IMPL_INL
