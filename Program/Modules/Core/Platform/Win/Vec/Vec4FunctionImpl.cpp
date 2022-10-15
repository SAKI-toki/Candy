/*****************************************************************//**
 * \file   Vec4FunctionImpl.cpp
 * \brief  Vector4関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4FunctionImpl.h"

#include <Core/Platform/Win/Vec/Vec4ConstantValues.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace VecFunctionImpl
{
	bool VecToBoolImpl(const vector_type _v, const s32 _mask)
	{
		const s32 vecMask = _mm_movemask_ps(_v);
		return (vecMask & _mask) == _mask;
	}
	bool VecToBoolXYZ(const vector_type _v)
	{
		return VecToBoolImpl(_v, 0x7);
	}
	bool VecToBoolXYZW(const vector_type _v)
	{
		return VecToBoolImpl(_v, 0xf);
	}
}

vector_type VecSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return _mm_setr_ps(_x, _y, _z, _w);
}
vector_type VecSetZeroImpl()
{
	return Vec4ConstantValues::Zero;
}
vector_type VecSetOneImpl()
{
	return Vec4ConstantValues::One;
}
vector_type VecSetXImpl(const vector_type _v, const f32 _x)
{
	vector_type temp = _mm_set_ss(_x);
	return _mm_move_ss(_v, temp);
}
vector_type VecSetYImpl(const vector_type _v, const f32 _y)
{
	vector_type v = VecPermuteImpl<CANDY_MM_SHUFFLE(1, 0, 2, 3)>(_v);
	vector_type temp = _mm_set_ss(_y);
	v = _mm_move_ss(v, temp);
	return VecPermuteImpl<CANDY_MM_SHUFFLE(1, 0, 2, 3)>(v);
}
vector_type VecSetZImpl(const vector_type _v, const f32 _z)
{
	vector_type v = VecPermuteImpl<CANDY_MM_SHUFFLE(2, 1, 0, 3)>(_v);
	vector_type temp = _mm_set_ss(_z);
	v = _mm_move_ss(v, temp);
	return VecPermuteImpl<CANDY_MM_SHUFFLE(2, 1, 0, 3)>(v);
}
vector_type VecSetWImpl(const vector_type _v, const f32 _w)
{
	vector_type v = VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(_v);
	vector_type temp = _mm_set_ss(_w);
	v = _mm_move_ss(v, temp);
	return VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(v);
}
vector_type VecSetZeroWImpl(const vector_type _v)
{
	vector_type v = VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(_v);
	v = _mm_move_ss(v, Vec4ConstantValues::Zero);
	return VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(v);
}
vector_type VecSetOneWImpl(const vector_type _v)
{
	vector_type v = VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(_v);
	v = _mm_move_ss(v, Vec4ConstantValues::One);
	return VecPermuteImpl<CANDY_MM_SHUFFLE(3, 1, 2, 0)>(v);
}

vector_type VecAddImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_add_ps(_v1, _v2);
}
vector_type VecSubImpl(const vector_type _v1, const vector_type _v2)
{
	return  _mm_sub_ps(_v1, _v2);
}
vector_type VecMulImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_mul_ps(_v1, _v2);
}
vector_type VecDivImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_div_ps(_v1, _v2);
}

vector_type VecSelectXImpl(const vector_type _v)
{
	return _mm_and_ps(_v, Vec4ConstantValues::SelectXMask);
}
vector_type VecSelectYImpl(const vector_type _v)
{
	return _mm_and_ps(_v, Vec4ConstantValues::SelectYMask);
}
vector_type VecSelectZImpl(const vector_type _v)
{
	return _mm_and_ps(_v, Vec4ConstantValues::SelectZMask);
}
vector_type VecSelectWImpl(const vector_type _v)
{
	return _mm_and_ps(_v, Vec4ConstantValues::SelectWMask);
}

// 内積の実装部
vector_type VecDotImpl(const vector_type _v1, const vector_type _v2)
{
	vector_type v, temp;
	v = VecMulImpl(_v1, _v2);
	temp = VecPermuteImpl<CANDY_MM_SHUFFLE(1, 2, 1, 2)>(v);
	v = _mm_add_ss(v, temp);
	temp = VecPermuteImpl<CANDY_MM_SHUFFLE(2, 2, 2, 2)>(v);
	v = _mm_add_ss(v, temp);
	return v;
}

// 外積の実装部
vector_type VecCrossImpl(const vector_type _v1, const vector_type _v2)
{
	vector_type result1, result2, temp1, temp2;
	temp1 = VecPermuteImpl<CANDY_MM_SHUFFLE(1, 2, 0, 3)>(_v1);
	temp2 = VecPermuteImpl<CANDY_MM_SHUFFLE(2, 0, 1, 3)>(_v2);
	result1 = VecMulImpl(temp1, temp2);
	temp1 = VecPermuteImpl<CANDY_MM_SHUFFLE(2, 0, 1, 3)>(_v1);
	temp2 = VecPermuteImpl<CANDY_MM_SHUFFLE(1, 2, 0, 3)>(_v2);
	result2 = VecMulImpl(temp1, temp2);
	return VecSubImpl(result1, result2);
}

vector_type VecMagImpl(const vector_type _v)
{
	return _mm_sqrt_ss(VecMagSqrImpl(_v));
}

vector_type VecMagSqrImpl(const vector_type _v)
{
	return VecDotImpl(_v, _v);
}

vector_type VecDistImpl(const vector_type _v1, const vector_type _v2)
{
	return _mm_sqrt_ss(VecDistSqrImpl(_v1, _v2));
}

vector_type VecDistSqrImpl(const vector_type _v1, const vector_type _v2)
{
	const vector_type v = VecSubImpl(_v1, _v2);
	return VecDotImpl(v, v);
}

vector_type VecNormalizeImpl(const vector_type _v)
{
	vector_type v = VecMagImpl(_v);

	if (VecFunctionImpl::VecToBoolImpl(_mm_cmple_ss(v, Vec4ConstantValues::Zero), 0x1))
	{
		return Vec4ConstantValues::Up;
	}

	v = _mm_div_ss(Vec4ConstantValues::One, v);
	v = VecPermuteImpl<CANDY_MM_SHUFFLE(0, 0, 0, 0)>(v);
	v = VecSetOneWImpl(v);

	return VecMulImpl(_v, v);
}

void VecSinCosImpl(vector_type& _outSin, vector_type& _outCos, const vector_type _v)
{
	const vector_type adjustV = VecAdjustAngleImpl(_v);

	const vector_type v2 = VecMulImpl(adjustV, adjustV);
	const vector_type v3 = VecMulImpl(v2, adjustV);
	const vector_type v4 = VecMulImpl(v2, v2);
	const vector_type v5 = VecMulImpl(v2, v3);
	const vector_type v6 = VecMulImpl(v3, v3);

	vector_type resultSin = adjustV;
	resultSin = VecSubImpl(resultSin, VecMulImpl(Vec4ConstantValues::SinCoefficient1, v3));
	resultSin = VecAddImpl(resultSin, VecMulImpl(Vec4ConstantValues::SinCoefficient2, v5));
	resultSin = VecSubImpl(resultSin, VecMulImpl(Vec4ConstantValues::SinCoefficient3, VecMulImpl(v3, v4)));
	resultSin = VecAddImpl(resultSin, VecMulImpl(Vec4ConstantValues::SinCoefficient4, VecMulImpl(v4, v5)));
	resultSin = VecSubImpl(resultSin, VecMulImpl(Vec4ConstantValues::SinCoefficient5, VecMulImpl(v5, v6)));
	_outSin = resultSin;

	vector_type resultCos = Vec4ConstantValues::One;
	resultCos = VecSubImpl(resultCos, VecMulImpl(Vec4ConstantValues::CosCoefficient1, v2));
	resultCos = VecAddImpl(resultCos, VecMulImpl(Vec4ConstantValues::CosCoefficient2, v4));
	resultCos = VecSubImpl(resultCos, VecMulImpl(Vec4ConstantValues::CosCoefficient3, v6));
	resultCos = VecAddImpl(resultCos, VecMulImpl(Vec4ConstantValues::CosCoefficient4, VecMulImpl(v2, v6)));
	resultCos = VecSubImpl(resultCos, VecMulImpl(Vec4ConstantValues::CosCoefficient5, VecMulImpl(v4, v6)));
	_outCos = resultCos;
}

vector_type VecRoundImpl(const vector_type _v)
{
	const vector_type cmp = _mm_cmpge_ps(_v, Vec4ConstantValues::Zero);
	const vector_type signHalf = _mm_blendv_ps(Vec4ConstantValues::NegativeHalf, Vec4ConstantValues::Half, cmp);
	const vector_type v = VecAddImpl(_v, signHalf);
	return _mm_round_ps(v, _MM_FROUND_TO_ZERO);
}

vector_type VecAdjustAngleImpl(const vector_type _v)
{
	const vector_type roundDivPi2 = VecRoundImpl(VecMulImpl(_v, Vec4ConstantValues::InvPi2));
	return VecSubImpl(_v, VecMulImpl(roundDivPi2, Vec4ConstantValues::Pi2));
}

bool IsVecZeroImpl(const vector_type _v)
{
	return VecFunctionImpl::VecToBoolXYZ(_mm_cmpeq_ps(_v, Vec4ConstantValues::Zero));
}
bool IsVecZeroXYZWImpl(const vector_type _v)
{
	return VecFunctionImpl::VecToBoolXYZW(_mm_cmpeq_ps(_v, Vec4ConstantValues::Zero));
}

CANDY_CORE_NAMESPACE_END
