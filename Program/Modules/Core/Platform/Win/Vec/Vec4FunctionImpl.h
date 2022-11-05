/*****************************************************************//**
 * \file   Vec4FunctionImpl.h
 * \brief  Vector4関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_IMPL_H
#define CANDY_CORE_VEC4_FUNCTION_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

vector_type VecSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
vector_type VecSetAllImpl(const f32 _v);
vector_type VecSetZeroImpl();
vector_type VecSetOneImpl();
vector_type VecSetXImpl(const vector_type _v, const f32 _x);
vector_type VecSetYImpl(const vector_type _v, const f32 _y);
vector_type VecSetZImpl(const vector_type _v, const f32 _z);
vector_type VecSetWImpl(const vector_type _v, const f32 _w);
vector_type VecSetZeroWImpl(const vector_type _v);
vector_type VecSetOneWImpl(const vector_type _v);

vector_type VecAddImpl(const vector_type _v1, const vector_type _v2);
vector_type VecSubImpl(const vector_type _v1, const vector_type _v2);
vector_type VecMulImpl(const vector_type _v1, const vector_type _v2);
vector_type VecDivImpl(const vector_type _v1, const vector_type _v2);

vector_type VecSelectXImpl(const vector_type _v);
vector_type VecSelectYImpl(const vector_type _v);
vector_type VecSelectZImpl(const vector_type _v);
vector_type VecSelectWImpl(const vector_type _v);

vector_type VecAndImpl(const vector_type _v1, const vector_type _v2);
vector_type VecOrImpl(const vector_type _v1, const vector_type _v2);

// 内積の実装部
vector_type VecDotImpl(const vector_type _v1, const vector_type _v2);

// 外積の実装部
vector_type VecCrossImpl(const vector_type _v1, const vector_type _v2);

vector_type VecMagImpl(const vector_type _v);
vector_type VecMagSqrImpl(const vector_type _v);

vector_type VecDistImpl(const vector_type _v1, const vector_type _v2);
vector_type VecDistSqrImpl(const vector_type _v1, const vector_type _v2);

vector_type VecNormalizeImpl(const vector_type _v);

void VecSinCosImpl(vector_type& _outSin, vector_type& _outCos, const vector_type _v);

vector_type VecRoundImpl(const vector_type _v);

vector_type VecAdjustAngleImpl(const vector_type _v);

template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
vector_type VecPermuteImpl(const vector_type _v);
template<u32 FP1, u32 FP2, u32 FP3, u32 FP4>
vector_type VecShuffleImpl(const vector_type _v1, const vector_type _v2);

// 判定の実装部
bool IsVecZeroImpl(const vector_type _v);
bool IsVecZeroXYZWImpl(const vector_type _v);

CANDY_CORE_NAMESPACE_END

#include "Vec4FunctionImpl.inl"

#endif // CANDY_CORE_VEC4_FUNCTION_IMPL_H
