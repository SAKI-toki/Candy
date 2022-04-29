#ifndef CANDY_STRING_SYSTEM_TO_UPPER_LOWER_H
#define CANDY_STRING_SYSTEM_TO_UPPER_LOWER_H

CANDY_NAMESPACE_BEGIN

namespace StringSystem
{
	constexpr char ToUpper(const char _c);
	constexpr char ToLower(const char _c);
}

CANDY_NAMESPACE_END

#include "StringSystemToUpperLower.inl"

#endif // CANDY_STRING_SYSTEM_TO_UPPER_LOWER_H
