#include "Path.h"

CANDY_NAMESPACE_BEGIN

std::string Path::FormatPath(std::string _path)
{
	while (true)
	{
		auto pos = _path.find(R"(/)");
		if (pos == _path.npos)break;
		_path.replace(pos, 1, R"(\)");
	}
	while (true)
	{
		auto pos = _path.find(R"(\\)");
		if (pos == _path.npos)break;
		_path.replace(pos, 2, R"(\)");
	}
	return _path;
}

CANDY_NAMESPACE_END
