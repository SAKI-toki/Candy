/*****************************************************************//**
 * \file   CoreProxyLogImpl.cpp
 * \brief  ログのプロキシの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "CoreProxyLogImpl.h"

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	// デバッグウィンドウへの出力
	void LogImpl::OutputDebugLog(const char* const _fmt, ...)
	{
		va_list args;
		va_start(args, _fmt);
		char buf[4096];
		vsprintf(buf, _fmt, args);
		va_end(args);
		::OutputDebugString(buf);
		::OutputDebugString("\n");
	}
}

CANDY_CORE_PROXY_NAMESPACE_END
