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

f32 VecDot(const Vec4 _v1, const Vec4 _v2);

Vec4 VecCross(const Vec4 _v1, const Vec4 _v2);

f32 VecMag(const Vec4 _v);
f32 VecMagSqr(const Vec4 _v);

f32 VecDist(const Vec4 _v1, const Vec4 _v2);
f32 VecDistSqr(const Vec4 _v1, const Vec4 _v2);

Vec4 VecNormalize(const Vec4 _v);

CANDY_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_H
