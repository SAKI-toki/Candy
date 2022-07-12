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
		void OutputDebugLog(const char* const _fmt, ...);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_LOG_IMPL_H
