/*****************************************************************//**
 * \file   MtxFunctionImpl.cpp
 * \brief  Matrix関連の関数の実装部
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxFunctionImpl.h"

#include <Core/Platform/Win/Vec/Vec4ConstantValues.h>

CANDY_CORE_NAMESPACE_BEGIN

void MtxSetImpl(vector_type(&_out)[4], const vector_type _v1, const vector_type _v2, const vector_type _v3, const vector_type _v4)
{
	_out[0] = _v1;
	_out[1] = _v2;
	_out[2] = _v3;
	_out[3] = _v4;
}

void MtxSetIdentityImpl(vector_type(&_out)[4])
{
	return MtxSetImpl(_out,
		VecSetImpl(1.0f, 0.0f, 0.0f, 0.0f),
		VecSetImpl(0.0f, 1.0f, 0.0f, 0.0f),
		VecSetImpl(0.0f, 0.0f, 1.0f, 0.0f),
		VecSetImpl(0.0f, 0.0f, 0.0f, 1.0f)
	);
}

void MtxTransposeImpl(vector_type(&_out)[4], const vector_type(&_m)[4])
{
	auto v1 = VecShuffleImpl<CANDY_MM_SHUFFLE(0, 1, 0, 1)>(_m[0], _m[1]);
	auto v2 = VecShuffleImpl<CANDY_MM_SHUFFLE(2, 3, 2, 3)>(_m[0], _m[1]);
	auto v3 = VecShuffleImpl<CANDY_MM_SHUFFLE(0, 1, 0, 1)>(_m[2], _m[3]);
	auto v4 = VecShuffleImpl<CANDY_MM_SHUFFLE(2, 3, 2, 3)>(_m[2], _m[3]);

	return MtxSetImpl(_out,
		VecShuffleImpl<CANDY_MM_SHUFFLE(0, 2, 0, 2)>(v1, v3),
		VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(v1, v3),
		VecShuffleImpl<CANDY_MM_SHUFFLE(0, 2, 0, 2)>(v2, v4),
		VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(v2, v4)
	);
}

//void MtxTransformationImpl(vector_type (&_out)[4], const vector_type _pos, const vector_type _rot, const vector_type _scale)
//{
//
//}

void MtxTranslationImpl(vector_type(&_out)[4], const vector_type _v)
{
	_out[0] = Vec4ConstantValues::Vec1000;
	_out[1] = Vec4ConstantValues::Vec0100;
	_out[2] = Vec4ConstantValues::Vec0010;
	_out[3] = VecSetOneWImpl(_v);
}

void MtxRotationZYXImpl(vector_type(&_out)[4], const vector_type /*_v*/)
{
	_out[0] = Vec4ConstantValues::Vec1000;
	_out[1] = Vec4ConstantValues::Vec0100;
	_out[2] = Vec4ConstantValues::Vec0010;
	_out[3] = Vec4ConstantValues::Vec0001;
}

void MtxScalingImpl(vector_type(&_out)[4], const vector_type _v)
{
	_out[0] = VecSelectXImpl(_v);
	_out[1] = VecSelectYImpl(_v);
	_out[2] = VecSelectZImpl(_v);
	_out[3] = Vec4ConstantValues::Vec0001;
}

CANDY_CORE_NAMESPACE_END
