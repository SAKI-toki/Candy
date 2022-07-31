/*****************************************************************//**
 * \file   CoreProxyLogImpl.h
 * \brief  ログのプロキシの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_LOG_IMPL_H
#define CANDY_CORE_PROXY_LOG_IMPL_H

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	namespace LogImpl
	{
		// デバッグウィンドウへの出力
		template<typename ...Types>
		void OutputDebugLog(const std::string_view _format, Types&& ..._args);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#include "CoreProxyLogImpl.inl"

#endif // CANDY_CORE_PROXY_LOG_IMPL_H
