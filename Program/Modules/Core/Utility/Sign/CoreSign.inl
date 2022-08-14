/*****************************************************************//**
 * \file   CoreSign.inl
 * \brief  Sign
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_SIGN_INL
#define CANDY_CORE_SIGN_INL

#include "CoreSign.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename ResultT>
ResultT Sign(const T _v)
{
	if (_v > 0)return static_cast<ResultT>(1);
	if (_v < 0)return static_cast<ResultT>(-1);
	return static_cast<ResultT>(0);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_SIGN_INL
