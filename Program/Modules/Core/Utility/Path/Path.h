/*****************************************************************//**
 * \file   Path.h
 * \brief  パス制御
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_PATH_H
#define CANDY_CORE_PATH_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Path
{
	std::string FormatPath(std::string _path);
	std::string FormatPath(const std::string_view _path);
	std::string GetExtension(const std::string_view _fileName);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_PATH_H
