/*****************************************************************//**
 * \file   CoreProxyLog.h
 * \brief  ログのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_DEBUG_LOG_H
#define CANDY_CORE_PROXY_DEBUG_LOG_H

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	namespace Log
	{
		// ログの初期化のプロキシ
		void StartupProxy();

		// ログの破棄のプロキシ
		void CleanupProxy();

		// ログの更新のプロキシ
		void UpdateProxy();

		// ログのプロキシ
		void AddLogProxy(const Color _color, const char* const _fileName, const s32 _lineNo,
			const char* const _funcName, const char* const _message);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_DEBUG_LOG_H
