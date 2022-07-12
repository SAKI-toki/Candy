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
	void Assert::CallAssertProxy(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName)
	{
		AssertImpl::CallAssertProxyImpl(_expr, _fileName, _lineNo, _funcName);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END
