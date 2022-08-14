/*****************************************************************//**
 * \file   CoreSign.h
 * \brief  Sign
 * \author Yu Ishiyama.
 * \date   2022/08/09
 *********************************************************************/

#ifndef CANDY_CORE_SIGN_H
#define CANDY_CORE_SIGN_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

template<typename T, typename ResultT = s32>
ResultT Sign(const T _v);

CANDY_CORE_NAMESPACE_END

#include "CoreSign.inl"

#endif // CANDY_CORE_SIGN_H
