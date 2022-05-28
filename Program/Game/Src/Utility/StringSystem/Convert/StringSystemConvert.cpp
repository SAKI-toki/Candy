#include "StringSystemConvert.h"

#if PLATFORM_WIN
#include <Utility/Platform/Win/StringSystem/Convert/StringSystemConvertImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

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

CANDY_NAMESPACE_END
