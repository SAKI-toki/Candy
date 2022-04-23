#ifndef CANDY_MATH_LOOP_H
#define CANDY_MATH_LOOP_H

CANDY_NAMESPACE_BEGIN

namespace Math
{
	template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
	ResultT Loop(const T _v, const MinT _min, const MaxT _max);

	template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
	ResultT LoopSize(const T _v, const MinT _min, const MaxT _max);

	template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
	ResultT LoopStrict(const T _v, const MinT _min, const MaxT _max);

	template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
	ResultT LoopSizeStrict(const T _v, const MinT _min, const MaxT _max);
}

CANDY_NAMESPACE_END

#include "Loop.inl"

#endif // CANDY_MATH_LOOP_H
