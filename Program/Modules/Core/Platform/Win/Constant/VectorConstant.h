/*****************************************************************//**
 * \file   VectorConstant.h
 * \brief  Vectorの定数(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VECTOR_CONSTANT_H
#define CANDY_CORE_VECTOR_CONSTANT_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace VectorConstant
{
	inline const vector_type Zero = _mm_setzero_ps();
	inline const vector_type Quarter = _mm_set_ps1(0.25f);
	inline const vector_type Half = _mm_set_ps1(0.5f);
	inline const vector_type One = _mm_set_ps1(1.0f);
	inline const vector_type Two = _mm_set_ps1(2.0f);

	inline const vector_type NegativeQuarter = _mm_set_ps1(-0.25f);
	inline const vector_type NegativeHalf = _mm_set_ps1(-0.5f);
	inline const vector_type NegativeOne = _mm_set_ps1(-1.0f);
	inline const vector_type NegativeTwo = _mm_set_ps1(-2.0f);

	inline const vector_type NegativeX = _mm_setr_ps(-1.0f, 1.0f, 1.0f, 1.0f);
	inline const vector_type NegativeY = _mm_setr_ps(1.0f, -1.0f, 1.0f, 1.0f);
	inline const vector_type NegativeZ = _mm_setr_ps(1.0f, 1.0f, -1.0f, 1.0f);
	inline const vector_type NegativeW = _mm_setr_ps(1.0f, 1.0f, 1.0f, -1.0f);

#define CONSTANT_VECTOR_DEFINE(A1, A2) \
inline const vector_type Negative##A1##A2 = _mm_mul_ps(Negative##A1, Negative##A2)
	CONSTANT_VECTOR_DEFINE(X, Y);
	CONSTANT_VECTOR_DEFINE(X, Z);
	CONSTANT_VECTOR_DEFINE(X, W);
	CONSTANT_VECTOR_DEFINE(Y, Z);
	CONSTANT_VECTOR_DEFINE(Y, W);
	CONSTANT_VECTOR_DEFINE(Z, W);
#undef CONSTANT_VECTOR_DEFINE

	inline const vector_type NegativeYZW = _mm_mul_ps(NegativeX, NegativeOne);
	inline const vector_type NegativeXZW = _mm_mul_ps(NegativeY, NegativeOne);
	inline const vector_type NegativeXYW = _mm_mul_ps(NegativeZ, NegativeOne);
	inline const vector_type NegativeXYZ = _mm_mul_ps(NegativeW, NegativeOne);

#define CONSTANT_VECTOR_DEFINE(X, Y, Z, W) \
inline const vector_type Vec##X##Y##Z##W = _mm_setr_ps(X, Y, Z, W);\
inline const vector_type SelectMask##X##Y##Z##W = _mm_cmpeq_ps(Vec##X##Y##Z##W, One)
	CONSTANT_VECTOR_DEFINE(0, 0, 0, 0);
	CONSTANT_VECTOR_DEFINE(0, 0, 0, 1);
	CONSTANT_VECTOR_DEFINE(0, 0, 1, 0);
	CONSTANT_VECTOR_DEFINE(0, 0, 1, 1);
	CONSTANT_VECTOR_DEFINE(0, 1, 0, 0);
	CONSTANT_VECTOR_DEFINE(0, 1, 0, 1);
	CONSTANT_VECTOR_DEFINE(0, 1, 1, 0);
	CONSTANT_VECTOR_DEFINE(0, 1, 1, 1);
	CONSTANT_VECTOR_DEFINE(1, 0, 0, 0);
	CONSTANT_VECTOR_DEFINE(1, 0, 0, 1);
	CONSTANT_VECTOR_DEFINE(1, 0, 1, 0);
	CONSTANT_VECTOR_DEFINE(1, 0, 1, 1);
	CONSTANT_VECTOR_DEFINE(1, 1, 0, 0);
	CONSTANT_VECTOR_DEFINE(1, 1, 0, 1);
	CONSTANT_VECTOR_DEFINE(1, 1, 1, 0);
	CONSTANT_VECTOR_DEFINE(1, 1, 1, 1);
#undef CONSTANT_VECTOR_DEFINE

	inline const vector_type Right = _mm_setr_ps(1.0f, 0.0f, 0.0f, 1.0f);
	inline const vector_type Up = _mm_setr_ps(0.0f, 1.0f, 0.0f, 1.0f);
	inline const vector_type Front = _mm_setr_ps(0.0f, 0.0f, 1.0f, 1.0f);

	inline const vector_type Pi = _mm_set_ps1(std::numbers::pi_v<float>);
	inline const vector_type Pi2 = _mm_set_ps1(std::numbers::pi_v<float> *2.0f);
	inline const vector_type InvPi = _mm_set_ps1(std::numbers::inv_pi_v<float>);
	inline const vector_type InvPi2 = _mm_set_ps1(std::numbers::inv_pi_v<float> *0.5f);

	inline const vector_type SinCoefficient1 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(3)));
	inline const vector_type SinCoefficient2 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(5)));
	inline const vector_type SinCoefficient3 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(7)));
	inline const vector_type SinCoefficient4 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(9)));
	inline const vector_type SinCoefficient5 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(11)));

	inline const vector_type CosCoefficient1 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(2)));
	inline const vector_type CosCoefficient2 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(4)));
	inline const vector_type CosCoefficient3 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(6)));
	inline const vector_type CosCoefficient4 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(8)));
	inline const vector_type CosCoefficient5 = _mm_set_ps1(1.0f / static_cast<float>(Factorial(10)));
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VECTOR_CONSTANT_H
