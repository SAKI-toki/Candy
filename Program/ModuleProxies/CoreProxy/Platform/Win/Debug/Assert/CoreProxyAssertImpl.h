/*****************************************************************//**
 * \file   CoreProxyAssertImpl.h
 * \brief  アサートのプロキシの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_ASSERT_IMPL_H
#define CANDY_CORE_PROXY_ASSERT_IMPL_H

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	namespace AssertImpl
	{
		// アサート呼び出しのプロキシの実装部
		void CallAssertProxyImpl(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName);
	}
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_ASSERT_IMPL_H
