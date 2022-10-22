﻿/*****************************************************************//**
 * \file   MtxFunction.cpp
 * \brief  Matrix関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxFunction.h"

CANDY_NAMESPACE_BEGIN

void MtxSet(Mtx& _out, const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4)
{
	core::MtxSetImpl(_out.vector, _v1.vector, _v2.vector, _v3.vector, _v4.vector);
}

void MtxSetIdentity(Mtx& _out)
{
	core::MtxSetIdentityImpl(_out.vector);
}

void MtxMul(Mtx& _out, const Mtx& _m1, const Mtx& _m2)
{
	core::MtxMulImpl(_out.vector, _m1.vector, _m2.vector);
}

void MtxTranspose(Mtx& _out, const Mtx& _m)
{
	core::MtxTransposeImpl(_out.vector, _m.vector);
}

void MtxTranslation(Mtx& _out, const Vec4& _v)
{
	core::MtxTranslationImpl(_out.vector, _v.vector);
}

void MtxRotationZXY(Mtx& _out, const Vec4& _v)
{
	core::MtxRotationZXYImpl(_out.vector, _v.vector);
}

void MtxScaling(Mtx& _out, const Vec4& _v)
{
	core::MtxScalingImpl(_out.vector, _v.vector);
}

CANDY_NAMESPACE_END
