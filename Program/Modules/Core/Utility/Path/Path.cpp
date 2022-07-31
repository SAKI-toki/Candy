/*****************************************************************//**
 * \file   Path.cpp
 * \brief  パス制御
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Path.h"

CANDY_CORE_NAMESPACE_BEGIN

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

std::string Path::FormatPath(const std::string_view _path)
{
	return FormatPath(std::string{ _path });
}

std::string Path::GetExtension(const std::string_view _fileName)
{
	auto pos = _fileName.find_last_of('.');
	if (pos == _fileName.npos)return "";
	return std::string{ _fileName.substr(pos) };
}

CANDY_CORE_NAMESPACE_END
