/*****************************************************************//**
 * \file   StringSystemConvert.h
 * \brief  文字列変換
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_STRING_SYSTEM_CONVERT_H
#define CANDY_CORE_STRING_SYSTEM_CONVERT_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace StringSystem
{
	std::wstring ConvertMultiByteToWideCharSJIS(const std::string_view _str);
	std::string ConvertWideCharToMultiByteSJIS(const std::wstring_view _wstr);
	
	std::wstring ConvertMultiByteToWideCharUTF8(const std::string_view _str);
	std::string ConvertWideCharToMultiByteUTF8(const std::wstring_view _wstr);

	std::string ConvertSJISToUTF8(const std::string_view _str);
	std::string ConvertUTF8ToSJIS(const std::string_view _str);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_STRING_SYSTEM_CONVERT_H
