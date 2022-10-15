/*****************************************************************//**
 * \file   CoreFactorial.inl
 * \brief  階乗
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_FACTORIAL_INL
#define CANDY_CORE_FACTORIAL_INL

#include "CoreFactorial.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename ResultT, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t>>
constexpr ResultT Factorial(const T _v)
{
	ResultT result = 1;
	for (T i = _v; i > 1; --i)
	{
		result *= i;
	}
	return result;
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FACTORIAL_INL
