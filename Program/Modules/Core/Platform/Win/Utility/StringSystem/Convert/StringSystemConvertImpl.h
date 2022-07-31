/*****************************************************************//**
 * \file   StringSystemConvertImpl.h
 * \brief  文字列返還の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_STRING_SYSTEM_CONVERT_IMPL_H
#define CANDY_CORE_STRING_SYSTEM_CONVERT_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace StringSystem::Impl
{
	std::wstring ConvertMultiByteToWideCharSJISImpl(const std::string_view _str);
	std::string ConvertWideCharToMultiByteSJISImpl(const std::wstring_view _wstr);

	std::wstring ConvertMultiByteToWideCharUTF8Impl(const std::string_view _str);
	std::string ConvertWideCharToMultiByteUTF8Impl(const std::wstring_view _wstr);

	std::string ConvertSJISToUTF8Impl(const std::string_view _str);
	std::string ConvertUTF8ToSJISImpl(const std::string_view _str);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_STRING_SYSTEM_CONVERT_IMPL_H
