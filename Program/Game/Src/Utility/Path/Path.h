#ifndef CANDY_PATH_H
#define CANDY_PATH_H

CANDY_NAMESPACE_BEGIN

namespace Path
{
	std::string FormatPath(std::string _path);
	std::string GetExtension(const std::string& _fileName);
}

CANDY_NAMESPACE_END

#endif // CANDY_PATH_H
