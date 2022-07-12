/*****************************************************************//**
 * \file   StringSystemToUpperLower.h
 * \brief  文字列の小文字大文字変換
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_STRING_SYSTEM_TO_UPPER_LOWER_H
#define CANDY_CORE_STRING_SYSTEM_TO_UPPER_LOWER_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace StringSystem
{
	constexpr char ToUpper(const char _c);
	constexpr char ToLower(const char _c);
}

CANDY_CORE_NAMESPACE_END

#include "StringSystemToUpperLower.inl"

#endif // CANDY_CORE_STRING_SYSTEM_TO_UPPER_LOWER_H
