/*****************************************************************//**
 * \file   MinMax.inl
 * \brief  MinMax
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MIN_MAX_INL
#define CANDY_CORE_MIN_MAX_INL

#include "MinMax.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T>
T Min(const T _v)
{
	return _v;
}

template<typename T1, typename T2, typename ...Types, typename ResultT>
ResultT Min(const T1 _v1, const T2 _v2, const Types... _tails)
{
	return Min((_v1 < _v2 ? _v1 : _v2), _tails...);
}

template<typename T>
T Max(const T _v)
{
	return _v;
}

template<typename T1, typename T2, typename ...Types, typename ResultT>
ResultT Max(const T1 _v1, const T2 _v2, const Types... _tails)
{
	return Max((_v1 > _v2 ? _v1 : _v2), _tails...);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MIN_MAX_INL
