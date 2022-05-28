#ifndef CANDY_STRING_SYSTEM_CONVERT_H
#define CANDY_STRING_SYSTEM_CONVERT_H

CANDY_NAMESPACE_BEGIN

namespace StringSystem
{
	std::wstring ConvertMultiByteToWideCharSJIS(const std::string& _str);
	std::string ConvertWideCharToMultiByteSJIS(const std::wstring& _wstr);
	
	std::wstring ConvertMultiByteToWideCharUTF8(const std::string& _str);
	std::string ConvertWideCharToMultiByteUTF8(const std::wstring& _wstr);

	std::string ConvertSJISToUTF8(const std::string& _str);
	std::string ConvertUTF8ToSJIS(const std::string& _str);
}

CANDY_NAMESPACE_END

#endif // CANDY_STRING_SYSTEM_CONVERT_H
