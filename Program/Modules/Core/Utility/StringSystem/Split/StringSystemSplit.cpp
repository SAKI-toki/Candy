/*****************************************************************//**
 * \file   StringSystemSplit.cpp
 * \brief  文字列分割
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "StringSystemSplit.h"

CANDY_CORE_NAMESPACE_BEGIN

std::vector<std::string> StringSystem::Split(const std::string_view _str, const std::string_view _separates)
{
	std::vector<std::string> result;

	size_t index = 0;

	while (index < _str.size())
	{
		auto pos = _str.find_first_of(_separates, index);

		if (pos == _str.npos)
		{
			pos = _str.size();
		}

		if (index != pos)
		{
			result.push_back(std::string{ _str.substr(index, pos - index) });
		}
		index = pos + 1;
	}

	return result;
}

CANDY_CORE_NAMESPACE_END
