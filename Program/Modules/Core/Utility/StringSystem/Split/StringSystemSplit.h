/*****************************************************************//**
 * \file   StringSystemSplit.h
 * \brief  文字列分割
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_STRING_SYSTEM_SPLIT_H
#define CANDY_CORE_STRING_SYSTEM_SPLIT_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace StringSystem
{
	std::vector<std::string> Split(const std::string& _str, const std::string& _separates);
}

CANDY_CORE_NAMESPACE_END

#include "StringSystemSplit.inl"

#endif // CANDY_CORE_STRING_SYSTEM_SPLIT_H
