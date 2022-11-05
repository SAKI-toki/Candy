/*****************************************************************//**
 * \file   Vec4Function.cpp
 * \brief  Vector4関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4Function.h"

CANDY_NAMESPACE_BEGIN

Vec4 VecSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return core::VecSetImpl(_x, _y, _z, _w);
}
Vec4 VecSetAll(const f32 _v)
{
	return core::VecSetAllImpl(_v);
}
Vec4 VecSetZero()
{
	return core::VecSetZeroImpl();
}
Vec4 VecSetOne()
{
	return core::VecSetOneImpl();
}
Vec4 VecSetX(const Vec4& _v, const f32 _x)
{
	return core::VecSetXImpl(_v.vector, _x);
}
Vec4 VecSetY(const Vec4& _v, const f32 _y)
{
	return core::VecSetYImpl(_v.vector, _y);
}
Vec4 VecSetZ(const Vec4& _v, const f32 _z)
{
	return core::VecSetZImpl(_v.vector, _z);
}
Vec4 VecSetW(const Vec4& _v, const f32 _w)
{
	return core::VecSetWImpl(_v.vector, _w);
}
Vec4 VecSetZeroW(const Vec4& _v)
{
	return core::VecSetZeroWImpl(_v.vector);
}
Vec4 VecSetOneW(const Vec4& _v)
{
	return core::VecSetOneWImpl(_v.vector);
}

Vec4 VecAdd(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecAddImpl(_v1.vector, _v2.vector);
}
Vec4 VecSub(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecSubImpl(_v1.vector, _v2.vector);
}
Vec4 VecMul(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecMulImpl(_v1.vector, _v2.vector);
}
Vec4 VecDiv(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecDivImpl(_v1.vector, _v2.vector);
}

Vec4 VecSelectX(const Vec4& _v)
{
	return core::VecSelectXImpl(_v.vector);
}
Vec4 VecSelectY(const Vec4& _v)
{
	return core::VecSelectYImpl(_v.vector);
}
Vec4 VecSelectZ(const Vec4& _v)
{
	return core::VecSelectZImpl(_v.vector);
}
Vec4 VecSelectW(const Vec4& _v)
{
	return core::VecSelectWImpl(_v.vector);
}

f32 VecDot(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ core::VecDotImpl(_v1.vector, _v2.vector) }.x;
}

Vec4 VecCross(const Vec4& _v1, const Vec4& _v2)
{
	return core::VecCrossImpl(_v1.vector, _v2.vector);
}

f32 VecMag(const Vec4& _v)
{
	return Vec4{ core::VecMagImpl(_v.vector) }.x;
}

f32 VecMagSqr(const Vec4& _v)
{
	return Vec4{ core::VecMagSqrImpl(_v.vector) }.x;
}

f32 VecDist(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ core::VecDistImpl(_v1.vector, _v2.vector) }.x;
}

f32 VecDistSqr(const Vec4& _v1, const Vec4& _v2)
{
	return Vec4{ core::VecDistSqrImpl(_v1.vector, _v2.vector) }.x;
}

Vec4 VecNormalize(const Vec4& _v)
{
	return core::VecNormalizeImpl(_v.vector);
}

void VecSinCos(Vec4& _outSin, Vec4& _outCos, const Vec4& _v)
{
	return core::VecSinCosImpl(_outSin.vector, _outCos.vector, _v.vector);
}

Vec4 VecRound(const Vec4& _v)
{
	return core::VecRoundImpl(_v.vector);
}

CANDY_NAMESPACE_END
