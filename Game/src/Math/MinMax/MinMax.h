#ifndef CANDY_MATH_MIN_MAX_H
#define CANDY_MATH_MIN_MAX_H

CANDY_NAMESPACE_BEGIN

namespace Math
{
	template<typename T1, typename T2, typename ...Types, typename ResultT = std::common_type_t<T1, T2, Types...>>
	ResultT Min(const T1 _v1, const T2 _v2, const Types... _tails);

	template<typename T1, typename T2, typename ...Types, typename ResultT = std::common_type_t<T1, T2, Types...>>
	ResultT Max(const T1 _v1, const T2 _v2, const Types... _tails);
}

CANDY_NAMESPACE_END

#include "MinMax.inl"

#endif // CANDY_MATH_MIN_MAX_H
