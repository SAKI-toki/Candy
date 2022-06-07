#include "Clamp.h"

CANDY_NAMESPACE_BEGIN

template<typename T, typename MinT, typename MaxT, typename ResultT>
ResultT Clamp(const T _v, const MinT _min, const MaxT _max)
{
	CANDY_ASSERT(_min < _max);
	if (_v < _min)return _min;
	if (_max < _v)return _max;
	return _v;
}

template<typename T>
T Clamp01(const T _v)
{
	return Clamp(_v, static_cast<T>(0), static_cast<T>(1));
}

CANDY_NAMESPACE_END
