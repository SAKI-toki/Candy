#include "StringSystemConvertImpl.h"

CANDY_NAMESPACE_BEGIN

std::wstring StringSystem::Impl::ConvertMultiByteToWideCharSJISImpl(const std::string& _str)
{
	const auto len = MultiByteToWideChar(CP_ACP, 0, _str.data(), static_cast<int>(_str.size()), nullptr, 0);
	std::wstring wstr;
	wstr.resize(len + 1);
	MultiByteToWideChar(CP_ACP, 0, _str.data(), static_cast<int>(_str.size()), wstr.data(), static_cast<int>(wstr.size()));
	return wstr;
}

std::string StringSystem::Impl::ConvertWideCharToMultiByteSJISImpl(const std::wstring& _wstr)
{
	const auto len = WideCharToMultiByte(CP_ACP, 0, _wstr.data(), static_cast<int>(_wstr.size()), nullptr, 0, nullptr, nullptr);
	std::string str;
	str.resize(len + 1);
	WideCharToMultiByte(CP_ACP, 0, _wstr.data(), static_cast<int>(_wstr.size()), str.data(), static_cast<int>(str.size()), nullptr, nullptr);
	return str;
}

std::wstring StringSystem::Impl::ConvertMultiByteToWideCharUTF8Impl(const std::string& _str)
{
	const auto len = MultiByteToWideChar(CP_UTF8, 0, _str.data(), static_cast<int>(_str.size()), nullptr, 0);
	std::wstring wstr;
	wstr.resize(len + 1);
	MultiByteToWideChar(CP_UTF8, 0, _str.data(), static_cast<int>(_str.size()), wstr.data(), static_cast<int>(wstr.size()));
	return wstr;
}

std::string StringSystem::Impl::ConvertWideCharToMultiByteUTF8Impl(const std::wstring& _wstr)
{
	const auto len = WideCharToMultiByte(CP_UTF8, 0, _wstr.data(), static_cast<int>(_wstr.size()), nullptr, 0, nullptr, nullptr);
	std::string str;
	str.resize(len + 1);
	WideCharToMultiByte(CP_UTF8, 0, _wstr.data(), static_cast<int>(_wstr.size()), str.data(), static_cast<int>(str.size()), nullptr, nullptr);
	return str;
}

std::string StringSystem::Impl::ConvertSJISToUTF8Impl(const std::string& _str)
{
	return ConvertWideCharToMultiByteUTF8Impl(ConvertMultiByteToWideCharSJISImpl(_str));
}

std::string StringSystem::Impl::ConvertUTF8ToSJISImpl(const std::string& _str)
{
	return ConvertWideCharToMultiByteSJISImpl(ConvertMultiByteToWideCharUTF8Impl(_str));
}

CANDY_NAMESPACE_END
