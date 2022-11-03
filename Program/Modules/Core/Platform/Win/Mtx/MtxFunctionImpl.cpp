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
			VecShuffleImpl<3, 0, 0, 3>(selectCosX, selectSinX),
			VecShuffleImpl<3, 0, 0, 3>(negativeSelectSinX, selectCosX),
			Vec4ConstantValues::Vec0001
		);
	}
	void MtxRotationYImpl(vector_type(&_out)[4], const vector_type _sin, const vector_type _cos)
	{
		const vector_type selectSinY = VecSelectYImpl(_sin);
		const vector_type selectCosY = VecSelectYImpl(_cos);

		const vector_type negativeSelectSinY = VecMulImpl(selectSinY, Vec4ConstantValues::NegativeY);

		MtxSetImpl(_out,
			VecShuffleImpl<1, 3, 1, 3>(selectCosY, negativeSelectSinY),
			Vec4ConstantValues::Vec0100,
			VecShuffleImpl<1, 3, 1, 3>(selectSinY, selectCosY),
			Vec4ConstantValues::Vec0001
		);
	}
	void MtxRotationZImpl(vector_type(&_out)[4], const vector_type _sin, const vector_type _cos)
	{
		const vector_type selectSinZ = VecSelectZImpl(_sin);
		const vector_type selectCosZ = VecSelectZImpl(_cos);

		const vector_type sinCosZ = VecShuffleImpl<2, 3, 2, 3>(selectSinZ, selectCosZ);

		const vector_type negativeSinCosZ = VecMulImpl(sinCosZ, Vec4ConstantValues::NegativeX);

		MtxSetImpl(_out,
			VecPermuteImpl<2, 0, 3, 3>(sinCosZ),
			VecPermuteImpl<0, 2, 3, 3>(negativeSinCosZ),
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
		vector_type x = VecPermuteImpl<0, 0, 0, 0>(_m1[i]);
		vector_type y = VecPermuteImpl<1, 1, 1, 1>(_m1[i]);
		vector_type z = VecPermuteImpl<2, 2, 2, 2>(_m1[i]);
		vector_type w = VecPermuteImpl<3, 3, 3, 3>(_m1[i]);

		x = VecMulImpl(x, _m2[0]);
		y = VecMulImpl(y, _m2[1]);
		z = VecMulImpl(z, _m2[2]);
		w = VecMulImpl(w, _m2[3]);

		_out[i] = VecAddImpl(x, VecAddImpl(y, VecAddImpl(z, w)));
	}
}

void MtxTransposeImpl(vector_type(&_out)[4], const vector_type(&_m)[4])
{
	const vector_type v1 = VecShuffleImpl<0, 1, 0, 1>(_m[0], _m[1]);
	const vector_type v2 = VecShuffleImpl<2, 3, 2, 3>(_m[0], _m[1]);
	const vector_type v3 = VecShuffleImpl<0, 1, 0, 1>(_m[2], _m[3]);
	const vector_type v4 = VecShuffleImpl<2, 3, 2, 3>(_m[2], _m[3]);

	MtxSetImpl(_out,
		VecShuffleImpl<0, 2, 0, 2>(v1, v3),
		VecShuffleImpl<1, 3, 1, 3>(v1, v3),
		VecShuffleImpl<0, 2, 0, 2>(v2, v4),
		VecShuffleImpl<1, 3, 1, 3>(v2, v4)
	);
}

void MtxTranslationImpl(vector_type(&_out)[4], const vector_type _v)
{
	MtxSetImpl(_out,
		Vec4ConstantValues::Vec1000,
		Vec4ConstantValues::Vec0100,
		Vec4ConstantValues::Vec0010,
		VecSetOneWImpl(_v)
	);
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
	MtxSetImpl(_out,
		VecSelectXImpl(_v),
		VecSelectYImpl(_v),
		VecSelectZImpl(_v),
		Vec4ConstantValues::Vec0001
	);
}

void MtxOrthographicImpl(vector_type(&_out)[4], const f32 _width, const f32 _height, const f32 _near, const f32 _far)
{
	const f32 range = 1.0f / (_far - _near);

	MtxSetImpl(_out,
		VecSetImpl(2.0f / _width, 0.0f, 0.0f, 0.0f),
		VecSetImpl(0.0f, 2.0f / _height, 0.0f, 0.0f),
		VecSetImpl(0.0f, 0.0f, range, 0.0f),
		VecSetImpl(0.0f, 0.0f, -range * _near, 1.0f)
	);
}

void MtxLookAtImpl(vector_type(&_out)[4], const vector_type _view, const vector_type _lookAt, const vector_type _up)
{
	const vector_type axisZ = VecNormalizeImpl(VecSubImpl(_lookAt, _view));
	const vector_type axisX = VecNormalizeImpl(VecCrossImpl(_up, axisZ));
	const vector_type axisY = VecCrossImpl(axisZ, axisX);

	const vector_type negativeView = VecMulImpl(_view, Vec4ConstantValues::NegativeOne);

	const vector_type dotX = VecShuffleImpl<2, 2, 0, 0>(axisX, VecSelectXImpl(VecDotImpl(axisX, negativeView)));
	const vector_type dotY = VecShuffleImpl<2, 2, 0, 0>(axisY, VecSelectXImpl(VecDotImpl(axisY, negativeView)));
	const vector_type dotZ = VecShuffleImpl<2, 2, 0, 0>(axisZ, VecSelectXImpl(VecDotImpl(axisZ, negativeView)));

	MtxSetImpl(_out,
		VecShuffleImpl<0, 1, 0, 2>(axisX, dotX),
		VecShuffleImpl<0, 1, 0, 2>(axisY, dotY),
		VecShuffleImpl<0, 1, 0, 2>(axisZ, dotZ),
		Vec4ConstantValues::Vec0001
	);

	MtxTransposeImpl(_out, _out);
}

CANDY_CORE_NAMESPACE_END
