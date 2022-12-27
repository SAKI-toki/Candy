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
		void CallAssertProxy(const std::string_view _expr, const std::string_view _fileName, const u32 _lineNo, 
			const std::string_view _funcName, const std::string_view _msg);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_DEBUG_ASSERT_H
