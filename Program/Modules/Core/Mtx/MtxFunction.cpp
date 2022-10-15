/*****************************************************************//**
 * \file   MtxFunction.cpp
 * \brief  Matrix関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxFunction.h"

CANDY_NAMESPACE_BEGIN

void MtxSet(Mtx& _out, const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4)
{
	return core::MtxSetImpl(_out.vector, _v1.vector, _v2.vector, _v3.vector, _v4.vector);
}

void MtxSetIdentity(Mtx& _out)
{
	return core::MtxSetIdentityImpl(_out.vector);
}

void MtxTranspose(Mtx& _out, const Mtx& _m)
{
	return core::MtxTransposeImpl(_out.vector, _m.vector);
}

CANDY_NAMESPACE_END
