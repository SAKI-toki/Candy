#ifndef CANDY_STRING_SYSTEM_CONVERT_IMPL_H
#define CANDY_STRING_SYSTEM_CONVERT_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace StringSystem::Impl
{
	std::wstring ConvertMultiByteToWideCharSJISImpl(const std::string& _str);
	std::string ConvertWideCharToMultiByteSJISImpl(const std::wstring& _wstr);

	std::wstring ConvertMultiByteToWideCharUTF8Impl(const std::string& _str);
	std::string ConvertWideCharToMultiByteUTF8Impl(const std::wstring& _wstr);

	std::string ConvertSJISToUTF8Impl(const std::string& _str);
	std::string ConvertUTF8ToSJISImpl(const std::string& _str);
}

CANDY_NAMESPACE_END

#endif // CANDY_STRING_SYSTEM_CONVERT_IMPL_H
