/*****************************************************************//**
 * \file   Vec4Function.h
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_FUNCTION_H
#define CANDY_CORE_VEC4_FUNCTION_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Vec/Vec4FunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

Vec4 VecSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
Vec4 VecSetZero();
Vec4 VecSetOne();
Vec4 VecSetX(const Vec4& _v, const f32 _x);
Vec4 VecSetY(const Vec4& _v, const f32 _y);
Vec4 VecSetZ(const Vec4& _v, const f32 _z);
Vec4 VecSetW(const Vec4& _v, const f32 _w);
Vec4 VecSetZeroW(const Vec4& _v);
Vec4 VecSetOneW(const Vec4& _v);

Vec4 VecAdd(const Vec4& _v1, const Vec4& _v2);
Vec4 VecSub(const Vec4& _v1, const Vec4& _v2);
Vec4 VecMul(const Vec4& _v1, const Vec4& _v2);
Vec4 VecDiv(const Vec4& _v1, const Vec4& _v2);

Vec4 VecSelectX(const Vec4& _v);
Vec4 VecSelectY(const Vec4& _v);
Vec4 VecSelectZ(const Vec4& _v);
Vec4 VecSelectW(const Vec4& _v);

f32 VecDot(const Vec4& _v1, const Vec4& _v2);

Vec4 VecCross(const Vec4& _v1, const Vec4& _v2);

f32 VecMag(const Vec4& _v);
f32 VecMagSqr(const Vec4& _v);

f32 VecDist(const Vec4& _v1, const Vec4& _v2);
f32 VecDistSqr(const Vec4& _v1, const Vec4& _v2);

Vec4 VecNormalize(const Vec4& _v);

void VecSinCos(Vec4& _outSin, Vec4& _outCos, const Vec4& _v);

Vec4 VecRound(const Vec4& _v);

template<u32 MM>
Vec4 VecPermute(const Vec4& _v);
template<u32 MM>
Vec4 VecShuffle(const Vec4& _v1, const Vec4& _v2);

CANDY_NAMESPACE_END

#include "Vec4Function.inl"

#endif // CANDY_CORE_VEC4_FUNCTION_H
