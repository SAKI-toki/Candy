/*****************************************************************//**
 * \file   Loop.inl
 * \brief  値のループ
 * \author Yu Ishiyama.
 * \date   2022/06/09
 *********************************************************************/

#include "Loop.h"

CANDY_CORE_NAMESPACE_BEGIN

// ループ
template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Loop(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return _max;
	if (_max < _v)return _min;
	return _v;
}

// ループ(サイズ)
template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT LoopSize(const T _v, const MinT _min, const MaxT _max)
{
	return Loop(_v, _min, _max - 1);
}

// ループ(厳密)
template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT LoopStrict(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return LoopStrict(_v + (_max - _min) + 1, _min, _max);
	if (_max < _v)return LoopStrict(_v - (_max - _min) - 1, _min, _max);
	return _v;
}

// ループ(サイズ・厳密)
template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT LoopSizeStrict(const T _v, const MinT _min, const MaxT _max)
{
	return LoopStrict(_v, _min, _max - 1);
}

CANDY_CORE_NAMESPACE_END
