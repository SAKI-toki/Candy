/*****************************************************************//**
 * \file   StringSystemConvertImpl.cpp
 * \brief  文字列返還の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "StringSystemConvertImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

std::wstring StringSystem::Impl::ConvertMultiByteToWideCharSJISImpl(const std::string& _str)
{
	const size_t len = MultiByteToWideChar(CP_ACP, 0, _str.data(), static_cast<int>(_str.size()), nullptr, 0);
	std::wstring wstr;
	wstr.resize(len + 1);
	MultiByteToWideChar(CP_ACP, 0, _str.data(), static_cast<int>(_str.size()), wstr.data(), static_cast<int>(wstr.size()));
	return wstr;
}

std::string StringSystem::Impl::ConvertWideCharToMultiByteSJISImpl(const std::wstring& _wstr)
{
	const size_t len = WideCharToMultiByte(CP_ACP, 0, _wstr.data(), static_cast<int>(_wstr.size()), nullptr, 0, nullptr, nullptr);
	std::string str;
	str.resize(len + 1);
	WideCharToMultiByte(CP_ACP, 0, _wstr.data(), static_cast<int>(_wstr.size()), str.data(), static_cast<int>(str.size()), nullptr, nullptr);
	return str;
}

std::wstring StringSystem::Impl::ConvertMultiByteToWideCharUTF8Impl(const std::string& _str)
{
	const size_t len = MultiByteToWideChar(CP_UTF8, 0, _str.data(), static_cast<int>(_str.size()), nullptr, 0);
	std::wstring wstr;
	wstr.resize(len + 1);
	MultiByteToWideChar(CP_UTF8, 0, _str.data(), static_cast<int>(_str.size()), wstr.data(), static_cast<int>(wstr.size()));
	return wstr;
}

std::string StringSystem::Impl::ConvertWideCharToMultiByteUTF8Impl(const std::wstring& _wstr)
{
	const size_t len = WideCharToMultiByte(CP_UTF8, 0, _wstr.data(), static_cast<int>(_wstr.size()), nullptr, 0, nullptr, nullptr);
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

CANDY_CORE_NAMESPACE_END
