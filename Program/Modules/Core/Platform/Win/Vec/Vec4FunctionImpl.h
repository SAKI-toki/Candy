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

Vec4 VecSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
Vec4 VecSetZeroImpl();

Vec4 VecAddImpl(const Vec4& _v1, const Vec4& _v2);
Vec4 VecSubImpl(const Vec4& _v1, const Vec4& _v2);
Vec4 VecMulImpl(const Vec4& _v1, const Vec4& _v2);
Vec4 VecDivImpl(const Vec4& _v1, const Vec4& _v2);

// 内積の実装部
f32 VecDotImpl(const Vec4& _v1, const Vec4& _v2);

// 外積の実装部
Vec4 VecCrossImpl(const Vec4& _v1, const Vec4& _v2);

f32 VecMagImpl(const Vec4& _v);
f32 VecMagSqrImpl(const Vec4& _v);

f32 VecDistImpl(const Vec4& _v1, const Vec4& _v2);
f32 VecDistSqrImpl(const Vec4& _v1, const Vec4& _v2);

Vec4 VecNormalizeImpl(const Vec4& _v);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_IMPL_H
