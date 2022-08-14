/*****************************************************************//**
 * \file   Clamp.inl
 * \brief  クランプ
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_CLAMP_INL
#define CANDY_CORE_CLAMP_INL

#include "Clamp.h"

CANDY_CORE_NAMESPACE_BEGIN

// 指定範囲にクランプ
template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Clamp(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return _min;
	if (_max < _v)return _max;
	return _v;
}

// [0-1]にクランプ
template<typename T>
T Clamp01(const T _v)
{
	return Clamp(_v, static_cast<T>(0), static_cast<T>(1));
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_CLAMP_INL
