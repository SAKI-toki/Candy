/*****************************************************************//**
 * \file   QuatFunctionImpl.cpp
 * \brief  Quaternion関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "QuatFunctionImpl.h"

#include <Core/Platform/Win/Constant/VectorConstant.h>

CANDY_CORE_NAMESPACE_BEGIN

vector_type QuatSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return _mm_setr_ps(_x, _y, _z, _w);
}

vector_type QuatSetIdentityImpl()
{
	return VectorConstant::Vec0001;
}

vector_type QuatMulImpl(const vector_type _q1, const vector_type _q2)
{
	const vector_type x1 = VecPermuteImpl<0, 0, 0, 0>(_q2);
	const vector_type y1 = VecPermuteImpl<1, 1, 1, 1>(_q2);
	const vector_type z1 = VecPermuteImpl<2, 2, 2, 2>(_q2);
	const vector_type w1 = VecPermuteImpl<3, 3, 3, 3>(_q2);

	const vector_type x2 = VecMulImpl(VecPermuteImpl<3, 2, 1, 0>(_q1), VectorConstant::NegativeYW);
	const vector_type y2 = VecMulImpl(VecPermuteImpl<2, 3, 0, 1>(_q1), VectorConstant::NegativeZW);
	const vector_type z2 = VecMulImpl(VecPermuteImpl<1, 0, 3, 2>(_q1), VectorConstant::NegativeXW);
	const vector_type w2 = VecPermuteImpl<0, 1, 2, 3>(_q1);

	const vector_type x = VecMulImpl(x1, x2);
	const vector_type y = VecMulImpl(y1, y2);
	const vector_type z = VecMulImpl(z1, z2);
	const vector_type w = VecMulImpl(w1, w2);

	return VecAddImpl(VecAddImpl(VecAddImpl(x, y), z), w);
}

vector_type AngleToQuatImpl(const vector_type _angle)
{
	vector_type outSin, outCos;
	VecSinCosImpl(outSin, outCos, VecMulImpl(_angle, VectorConstant::Half));
	const vector_type sinX = VecPermuteImpl<0, 0, 0, 0>(outSin);
	const vector_type cosX = VecPermuteImpl<0, 0, 0, 0>(outCos);
	const vector_type sinY = VecPermuteImpl<1, 1, 1, 1>(outSin);
	const vector_type cosY = VecPermuteImpl<1, 1, 1, 1>(outCos);
	const vector_type sinZ = VecPermuteImpl<2, 2, 2, 2>(outSin);
	const vector_type cosZ = VecPermuteImpl<2, 2, 2, 2>(outCos);

	const vector_type x1 = VecOrImpl(VecAndImpl(sinX, VectorConstant::SelectMask1000), VecAndImpl(cosX, VectorConstant::SelectMask0111));
	const vector_type x2 = VecOrImpl(VecAndImpl(sinX, VectorConstant::SelectMask0111), VecAndImpl(cosX, VectorConstant::SelectMask1000));
	const vector_type y1 = VecOrImpl(VecAndImpl(sinY, VectorConstant::SelectMask0100), VecAndImpl(cosY, VectorConstant::SelectMask1011));
	const vector_type y2 = VecOrImpl(VecAndImpl(sinY, VectorConstant::SelectMask1011), VecAndImpl(cosY, VectorConstant::SelectMask0100));
	const vector_type z1 = VecOrImpl(VecAndImpl(sinZ, VectorConstant::SelectMask0010), VecAndImpl(cosZ, VectorConstant::SelectMask1101));
	const vector_type z2 = VecOrImpl(VecAndImpl(sinZ, VectorConstant::SelectMask1101), VecAndImpl(cosZ, VectorConstant::SelectMask0010));

	const vector_type v1 = VecMulImpl(VecMulImpl(x1, y1), z1);
	const vector_type v2 = VecMulImpl(VecMulImpl(VecMulImpl(x2, y2), z2), VectorConstant::NegativeYZ);

	return VecAddImpl(v1, v2);
}

vector_type QuatSlerpImpl(const vector_type _q1, const vector_type _q2, const f32 _time)
{
	return DirectX::XMQuaternionSlerp(_q1, _q2, _time);
}

CANDY_CORE_NAMESPACE_END
