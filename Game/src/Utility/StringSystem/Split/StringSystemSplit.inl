#include "StringSystemSplit.h"

CANDY_NAMESPACE_BEGIN

inline std::vector<std::string> StringSystem::Split(const std::string& _str, const std::string& _separates)
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
			result.push_back(_str.substr(index, pos - index));
		}
		index = pos + 1;
	}

	return result;
}

CANDY_NAMESPACE_END
