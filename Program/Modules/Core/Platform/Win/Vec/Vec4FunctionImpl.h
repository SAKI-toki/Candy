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

// 内積の実装部
f32 VecDotImpl(const Vec4Impl _v1, const Vec4Impl _v2);

// 外積の実装部
Vec4Impl VecCrossImpl(const Vec4Impl _v1, const Vec4Impl _v2);

f32 VecMagImpl(const Vec4Impl _v);
f32 VecMagSqrImpl(const Vec4Impl _v);

f32 VecDistImpl(const Vec4Impl _v1, const Vec4Impl _v2);
f32 VecDistSqrImpl(const Vec4Impl _v1, const Vec4Impl _v2);

Vec4Impl VecNormalizeImpl(const Vec4Impl _v);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_FUNCTION_IMPL_H
