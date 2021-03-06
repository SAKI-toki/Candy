/*****************************************************************//**
 * \file   CoreProxyAssert.h
 * \brief  アサートのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_DEBUG_ASSERT_H
#define CANDY_CORE_PROXY_DEBUG_ASSERT_H

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	namespace Assert
	{
		// アサート呼び出しのプロキシ
		void CallAssertProxy(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_DEBUG_ASSERT_H
