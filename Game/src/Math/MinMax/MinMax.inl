#include "MinMax.h"

CANDY_NAMESPACE_BEGIN

namespace Math
{
	namespace Impl
	{
		template<typename T>
		T Min(const T _v)
		{
			return _v;
		}

		template<typename T1, typename T2, typename ...Types, typename ResultT = std::common_type_t<T1, T2, Types...>>
		ResultT Min(const T1 _v1, const T2 _v2, const Types... _tails)
		{
			return Min((_v1 < _v2 ? _v1 : _v2), _tails...);
		}

		template<typename T>
		T Max(const T _v)
		{
			return _v;
		}

		template<typename T1, typename T2, typename ...Types, typename ResultT = std::common_type_t<T1, T2, Types...>>
		ResultT Max(const T1 _v1, const T2 _v2, const Types... _tails)
		{
			return Max((_v1 > _v2 ? _v1 : _v2), _tails...);
		}
	}
}

template<typename T1, typename T2, typename ...Types, typename ResultT>
ResultT Math::Min(const T1 _v1, const T2 _v2, const Types... _tails)
{
	return Impl::Min(_v1, _v2, _tails...);
}

template<typename T1, typename T2, typename ...Types, typename ResultT>
ResultT Math::Max(const T1 _v1, const T2 _v2, const Types... _tails)
{
	return Impl::Min(_v1, _v2, _tails...);
}

CANDY_NAMESPACE_END
