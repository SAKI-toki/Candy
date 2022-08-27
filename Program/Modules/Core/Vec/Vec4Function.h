/*****************************************************************//**
 * \file   Vec4Function.h
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_H
#define CANDY_CORE_VEC4_FUNCTION_H

#include <Core/CoreInclude.h>

CANDY_NAMESPACE_BEGIN

Vec4 VecSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
Vec4 VecSetZero();

Vec4 VecAdd(const Vec4& _v1, const Vec4& _v2);
Vec4 VecSub(const Vec4& _v1, const Vec4& _v2);
Vec4 VecMul(const Vec4& _v1, const Vec4& _v2);
Vec4 VecDiv(const Vec4& _v1, const Vec4& _v2);

f32 VecDot(const Vec4& _v1, const Vec4& _v2);

Vec4 VecCross(const Vec4& _v1, const Vec4& _v2);

f32 VecMag(const Vec4& _v);
f32 VecMagSqr(const Vec4& _v);

f32 VecDist(const Vec4& _v1, const Vec4& _v2);
f32 VecDistSqr(const Vec4& _v1, const Vec4& _v2);

Vec4 VecNormalize(const Vec4& _v);

CANDY_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_H
