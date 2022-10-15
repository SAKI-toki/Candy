/*****************************************************************//**
 * \file   CoreFactorial.h
 * \brief  階乗
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_FACTORIAL_H
#define CANDY_CORE_FACTORIAL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename ResultT = T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
constexpr ResultT Factorial(const T _v);

CANDY_CORE_NAMESPACE_END

#include "CoreFactorial.inl"

#endif // CANDY_CORE_FACTORIAL_H
