#ifndef CANDY_STRING_SYSTEM_SPLIT_H
#define CANDY_STRING_SYSTEM_SPLIT_H

CANDY_NAMESPACE_BEGIN

namespace StringSystem
{
	std::vector<std::string> Split(const std::string& _str, const std::string& _separates);
}

CANDY_NAMESPACE_END

#include "StringSystemSplit.inl"

#endif // CANDY_STRING_SYSTEM_SPLIT_H
