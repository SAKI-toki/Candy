/*****************************************************************//**
 * \file   StringSystemConvert.cpp
 * \brief  文字列変換
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "StringSystemConvert.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Utility/StringSystem/Convert/StringSystemConvertImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

std::wstring StringSystem::ConvertMultiByteToWideCharSJIS(const std::string& _str)
{
	return Impl::ConvertMultiByteToWideCharSJISImpl(_str);
}

std::string StringSystem::ConvertWideCharToMultiByteSJIS(const std::wstring& _wstr)
{
	return Impl::ConvertWideCharToMultiByteSJISImpl(_wstr);
}

std::wstring StringSystem::ConvertMultiByteToWideCharUTF8(const std::string& _str)
{
	return Impl::ConvertMultiByteToWideCharUTF8Impl(_str);
}

std::string StringSystem::ConvertWideCharToMultiByteUTF8(const std::wstring& _wstr)
{
	return Impl::ConvertWideCharToMultiByteUTF8Impl(_wstr);
}

std::string StringSystem::ConvertSJISToUTF8(const std::string& _str)
{
	return Impl::ConvertSJISToUTF8Impl(_str);
}

std::string StringSystem::ConvertUTF8ToSJIS(const std::string& _str)
{
	return Impl::ConvertUTF8ToSJISImpl(_str);
}

CANDY_CORE_NAMESPACE_END
