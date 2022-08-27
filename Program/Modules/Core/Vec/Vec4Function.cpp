/*****************************************************************//**
 * \file   Vec4Function.cpp
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4Function.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Vec/Vec4FunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

Vec4 VecSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return core::VecSetImpl(_x, _y, _z, _w);
}
Vec4 VecSetZero()
{
	return core::VecSetZeroImpl();
}

Vec4 VecAdd(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecAddImpl(_v1, _v2);
}
Vec4 VecSub(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecSubImpl(_v1, _v2);
}
Vec4 VecMul(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecMulImpl(_v1, _v2);
}
Vec4 VecDiv(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecDivImpl(_v1, _v2);
}

f32 VecDot(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecDotImpl(_v1, _v2);
}

Vec4 VecCross(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecCrossImpl(_v1, _v2);
}

f32 VecMag(const Vec4& _v)
{
	return core::VecMagImpl(_v);
}

f32 VecMagSqr(const Vec4& _v)
{
	return core::VecMagSqrImpl(_v);
}

f32 VecDist(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecDistImpl(_v1, _v2);
}

f32 VecDistSqr(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecDistSqrImpl(_v1, _v2);
}

Vec4 VecNormalize(const Vec4& _v)
{
	return core::VecNormalizeImpl(_v);
}

CANDY_NAMESPACE_END
