#include "StringSystemToUpperLower.h"

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
