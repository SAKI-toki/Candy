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

std::string Path::GetExtension(const std::string& _fileName)
{
	auto pos = _fileName.find_last_of('.');
	if (pos == _fileName.npos)return "";
	return _fileName.substr(pos);
}

CANDY_NAMESPACE_END
