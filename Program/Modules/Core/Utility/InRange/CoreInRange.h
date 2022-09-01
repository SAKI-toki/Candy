/*****************************************************************//**
 * \file   CoreInRange.h
 * \brief  範囲内判定
 * \author Yu Ishiyama.
 * \date   2022/08/09
 *********************************************************************/

#ifndef CANDY_CORE_IN_RANGE_H
#define CANDY_CORE_IN_RANGE_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename MinT, typename MaxT>
bool InRange(const T _v, const MinT _min, const MaxT _max);

template<typename T, typename MinT, typename MaxT>
bool InRangeSize(const T _v, const MinT _min, const MaxT _max);

CANDY_CORE_NAMESPACE_END

#include "CoreInRange.inl"

#endif // CANDY_CORE_IN_RANGE_H
