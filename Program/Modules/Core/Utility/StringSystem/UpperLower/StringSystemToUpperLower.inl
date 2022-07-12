/*****************************************************************//**
 * \file   StringSystemToUpperLower.inl
 * \brief  文字列の小文字大文字変換
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "StringSystemToUpperLower.h"

CANDY_CORE_NAMESPACE_BEGIN

inline constexpr char StringSystem::ToUpper(const char _c)
{
	if ('a' <= _c && _c <= 'z')
	{
		return _c - 'a' + 'A';
	}
	return _c;
}

inline constexpr char StringSystem::ToLower(const char _c)
{
	if ('A' <= _c && _c <= 'Z')
	{
		return _c - 'A' + 'a';
	}
	return _c;
}

CANDY_CORE_NAMESPACE_END
