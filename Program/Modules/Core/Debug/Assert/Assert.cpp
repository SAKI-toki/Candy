/*****************************************************************//**
 * \file   Assert.cpp
 * \brief  アサートの呼び出し
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Assert.h"
#include <CoreProxy/Debug/Assert/CoreProxyAssert.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	// アサート呼び出し
	void Assert::CallAssert(const std::string_view _expr, const std::string_view _fileName, const u32 _lineNo, const std::string_view _funcName)
	{
		coreProxy::Debug::Assert::CallAssertProxy(_expr, _fileName, _lineNo, _funcName);

		std::abort();
	}
}

CANDY_CORE_NAMESPACE_END
