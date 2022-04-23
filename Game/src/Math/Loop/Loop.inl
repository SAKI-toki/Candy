#include "Loop.h"

CANDY_NAMESPACE_BEGIN

template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Math::Loop(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return _max;
	if (_max < _v)return _min;
	return _v;
}

template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Math::LoopSize(const T _v, const MinT _min, const MaxT _max)
{
	return Loop(_v, _min, _max - 1);
}

template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Math::LoopStrict(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return _max - (_min - _v);
	if (_max < _v)return _min + (_v - _max);
	return _v;
}

template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT LoopSizeStrict(const T _v, const MinT _min, const MaxT _max)
{
	return Loop(_v, _min, _max - 1);
}

CANDY_NAMESPACE_END
