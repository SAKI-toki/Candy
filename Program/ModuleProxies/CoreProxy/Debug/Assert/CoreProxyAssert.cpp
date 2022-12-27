/*****************************************************************//**
 * \file   CoreProxyAssert.cpp
 * \brief  アサートのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include "CoreProxyAssert.h"

#if PLATFORM_WIN
#include <CoreProxy/Platform/Win/Debug/Assert/CoreProxyAssertImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	// アサート呼び出しのプロキシ
	void Assert::CallAssertProxy(const std::string_view _expr, const std::string_view _fileName, const u32 _lineNo, 
		const std::string_view _funcName, const std::string_view _msg)
	{
		AssertImpl::CallAssertProxyImpl(_expr, _fileName, _lineNo, _funcName, _msg);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END
