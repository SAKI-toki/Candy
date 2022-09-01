/*****************************************************************//**
 * \file   CoreInRange.inl
 * \brief  範囲内判定
 * \author Yu Ishiyama.
 * \date   2022/08/09
 *********************************************************************/

#ifndef CANDY_CORE_IN_RANGE_INL
#define CANDY_CORE_IN_RANGE_INL

#include "CoreInRange.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename MinT, typename MaxT>
bool InRange(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min <= _max);
	return _min <= _v && _v <= _max;
}

template<typename T, typename MinT, typename MaxT>
bool InRangeSize(const T _v, const MinT _min, const MaxT _max)
{
	return InRange(_v, _min, _max - 1);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_IN_RANGE_INL
