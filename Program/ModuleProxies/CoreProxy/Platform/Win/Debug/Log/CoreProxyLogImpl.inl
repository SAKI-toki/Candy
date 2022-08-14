/*****************************************************************//**
 * \file   CoreProxyLogImpl.inl
 * \brief  ログのプロキシの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_LOG_IMPL_INL
#define CANDY_CORE_PROXY_LOG_IMPL_INL

#include "CoreProxyLogImpl.h"

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	// デバッグウィンドウへの出力
	template<typename ...Types>
	void LogImpl::OutputDebugLog(
		CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
		CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
	{
#if BUILD_DEBUG
		::OutputDebugString(std::format(_format, std::forward<Types>(_args)...).c_str());
		::OutputDebugString("\n");
#endif // BUILD_DEBUG
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_LOG_IMPL_INL
