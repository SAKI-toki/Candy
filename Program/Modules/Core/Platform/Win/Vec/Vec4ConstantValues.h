﻿/*****************************************************************//**
 * \file   Vec4ConstantValues.h
 * \brief  Vector4関連の定数(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_CONSTANT_VALUES_H
#define CANDY_CORE_VEC4_CONSTANT_VALUES_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Vec4ConstantValues
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

	inline const vector_type Vec1000 = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
	inline const vector_type Vec0100 = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
	inline const vector_type Vec0010 = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
	inline const vector_type Vec0001 = _mm_setr_ps(0.0f, 0.0f, 0.0f, 1.0f);

	inline const vector_type Right = _mm_setr_ps(1.0f, 0.0f, 0.0f, 1.0f);
	inline const vector_type Up = _mm_setr_ps(0.0f, 1.0f, 0.0f, 1.0f);
	inline const vector_type Front = _mm_setr_ps(0.0f, 0.0f, 1.0f, 1.0f);

	inline const vector_type Pi = _mm_set_ps1(std::numbers::pi_v<float>);
	inline const vector_type Pi2 = _mm_set_ps1(std::numbers::pi_v<float> *2.0f);
	inline const vector_type InvPi = _mm_set_ps1(std::numbers::inv_pi_v<float>);
	inline const vector_type InvPi2 = _mm_set_ps1(std::numbers::inv_pi_v<float> *0.5f);

	inline const vector_type SelectXMask = _mm_cmpeq_ps(VecSetImpl(1.0f, 0.0f, 0.0f, 0.0f), One);
	inline const vector_type SelectYMask = _mm_cmpeq_ps(VecSetImpl(0.0f, 1.0f, 0.0f, 0.0f), One);
	inline const vector_type SelectZMask = _mm_cmpeq_ps(VecSetImpl(0.0f, 0.0f, 1.0f, 0.0f), One);
	inline const vector_type SelectWMask = _mm_cmpeq_ps(VecSetImpl(0.0f, 0.0f, 0.0f, 1.0f), One);

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

#endif // CANDY_CORE_VEC4_CONSTANT_VALUES_H