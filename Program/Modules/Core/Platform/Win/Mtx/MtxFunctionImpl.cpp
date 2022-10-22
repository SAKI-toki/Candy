/*****************************************************************//**
 * \file   MtxFunctionImpl.cpp
 * \brief  Matrix関連の関数の実装部
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxFunctionImpl.h"

#include <Core/Platform/Win/Vec/Vec4ConstantValues.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace MtxFunctionImpl
{
	void MtxRotationXImpl(vector_type(&_out)[4], const vector_type _sin, const vector_type _cos)
	{
		const vector_type selectSinX = VecSelectXImpl(_sin);
		const vector_type selectCosX = VecSelectXImpl(_cos);

		const vector_type negativeSelectSinX = VecMulImpl(selectSinX, Vec4ConstantValues::NegativeX);

		MtxSetImpl(_out,
			Vec4ConstantValues::Vec1000,
			VecShuffleImpl<CANDY_MM_SHUFFLE(3, 0, 0, 3)>(selectCosX, selectSinX),
			VecShuffleImpl<CANDY_MM_SHUFFLE(3, 0, 0, 3)>(negativeSelectSinX, selectCosX),
			Vec4ConstantValues::Vec0001
		);
	}
	void MtxRotationYImpl(vector_type(&_out)[4], const vector_type _sin, const vector_type _cos)
	{
		const vector_type selectSinY = VecSelectYImpl(_sin);
		const vector_type selectCosY = VecSelectYImpl(_cos);

		const vector_type negativeSelectSinY = VecMulImpl(selectSinY, Vec4ConstantValues::NegativeY);

		MtxSetImpl(_out,
			VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(selectCosY, negativeSelectSinY),
			Vec4ConstantValues::Vec0100,
			VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(selectSinY, selectCosY),
			Vec4ConstantValues::Vec0001
		);
	}
	void MtxRotationZImpl(vector_type(&_out)[4], const vector_type _sin, const vector_type _cos)
	{
		const vector_type selectSinZ = VecSelectZImpl(_sin);
		const vector_type selectCosZ = VecSelectZImpl(_cos);

		const vector_type sinCosZ = VecShuffleImpl<CANDY_MM_SHUFFLE(2, 3, 2, 3)>(selectSinZ, selectCosZ);

		const vector_type negativeSinCosZ = VecMulImpl(sinCosZ, Vec4ConstantValues::NegativeX);

		MtxSetImpl(_out,
			VecPermuteImpl<CANDY_MM_SHUFFLE(2, 0, 3, 3)>(sinCosZ),
			VecPermuteImpl<CANDY_MM_SHUFFLE(0, 2, 3, 3)>(negativeSinCosZ),
			Vec4ConstantValues::Vec0010,
			Vec4ConstantValues::Vec0001
		);
	}
}

void MtxSetImpl(vector_type(&_out)[4], const vector_type _v1, const vector_type _v2, const vector_type _v3, const vector_type _v4)
{
	_out[0] = _v1;
	_out[1] = _v2;
	_out[2] = _v3;
	_out[3] = _v4;
}

void MtxSetIdentityImpl(vector_type(&_out)[4])
{
	MtxSetImpl(_out,
		VecSetImpl(1.0f, 0.0f, 0.0f, 0.0f),
		VecSetImpl(0.0f, 1.0f, 0.0f, 0.0f),
		VecSetImpl(0.0f, 0.0f, 1.0f, 0.0f),
		VecSetImpl(0.0f, 0.0f, 0.0f, 1.0f)
	);
}

void MtxMulImpl(vector_type(&_out)[4], const vector_type(&_m1)[4], const vector_type(&_m2)[4])
{
	for (s32 i = 0; i < 4; ++i)
	{
		vector_type x = VecPermuteImpl<CANDY_MM_SHUFFLE(0, 0, 0, 0)>(_m1[i]);
		vector_type y = VecPermuteImpl<CANDY_MM_SHUFFLE(1, 1, 1, 1)>(_m1[i]);
		vector_type z = VecPermuteImpl<CANDY_MM_SHUFFLE(2, 2, 2, 2)>(_m1[i]);
		vector_type w = VecPermuteImpl<CANDY_MM_SHUFFLE(3, 3, 3, 3)>(_m1[i]);

		x = VecMulImpl(x, _m2[0]);
		y = VecMulImpl(y, _m2[1]);
		z = VecMulImpl(z, _m2[2]);
		w = VecMulImpl(w, _m2[3]);

		_out[i] = VecAddImpl(x, VecAddImpl(y, VecAddImpl(z, w)));
	}
}

void MtxTransposeImpl(vector_type(&_out)[4], const vector_type(&_m)[4])
{
	const vector_type v1 = VecShuffleImpl<CANDY_MM_SHUFFLE(0, 1, 0, 1)>(_m[0], _m[1]);
	const vector_type v2 = VecShuffleImpl<CANDY_MM_SHUFFLE(2, 3, 2, 3)>(_m[0], _m[1]);
	const vector_type v3 = VecShuffleImpl<CANDY_MM_SHUFFLE(0, 1, 0, 1)>(_m[2], _m[3]);
	const vector_type v4 = VecShuffleImpl<CANDY_MM_SHUFFLE(2, 3, 2, 3)>(_m[2], _m[3]);

	MtxSetImpl(_out,
		VecShuffleImpl<CANDY_MM_SHUFFLE(0, 2, 0, 2)>(v1, v3),
		VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(v1, v3),
		VecShuffleImpl<CANDY_MM_SHUFFLE(0, 2, 0, 2)>(v2, v4),
		VecShuffleImpl<CANDY_MM_SHUFFLE(1, 3, 1, 3)>(v2, v4)
	);
}

void MtxTranslationImpl(vector_type(&_out)[4], const vector_type _v)
{
	_out[0] = Vec4ConstantValues::Vec1000;
	_out[1] = Vec4ConstantValues::Vec0100;
	_out[2] = Vec4ConstantValues::Vec0010;
	_out[3] = VecSetOneWImpl(_v);
}

void MtxRotationZXYImpl(vector_type(&_out)[4], const vector_type _v)
{
	vector_type outSin, outCos;
	VecSinCosImpl(outSin, outCos, _v);

	vector_type mtxX[4], mtxY[4], mtxZ[4];
	MtxFunctionImpl::MtxRotationXImpl(mtxX, outSin, outCos);
	MtxFunctionImpl::MtxRotationYImpl(mtxY, outSin, outCos);
	MtxFunctionImpl::MtxRotationZImpl(mtxZ, outSin, outCos);

	vector_type mtxZY[4];
	MtxMulImpl(mtxZY, mtxZ, mtxX);
	MtxMulImpl(_out, mtxZY, mtxY);
}

void MtxScalingImpl(vector_type(&_out)[4], const vector_type _v)
{
	_out[0] = VecSelectXImpl(_v);
	_out[1] = VecSelectYImpl(_v);
	_out[2] = VecSelectZImpl(_v);
	_out[3] = Vec4ConstantValues::Vec0001;
}

CANDY_CORE_NAMESPACE_END
