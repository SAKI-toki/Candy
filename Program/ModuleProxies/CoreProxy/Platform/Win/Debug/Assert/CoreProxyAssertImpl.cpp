/*****************************************************************//**
 * \file   CoreProxyAssertImpl.cpp
 * \brief  アサートのプロキシの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "CoreProxyAssertImpl.h"

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
	// アサート呼び出しのプロキシの実装部
	void AssertImpl::CallAssertProxyImpl(
		CANDY_UNUSED_VALUE_ATTR const std::string_view _expr, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _fileName, 
		CANDY_UNUSED_VALUE_ATTR const u32 _lineNo, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _funcName,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _msg)
	{
#if BUILD_DEBUG
		const auto message = std::format({ "場所:{0}({1}){2}\n不正:{3},{4}" }, _fileName, _lineNo, _funcName, _expr, _msg);
		::MessageBox(NULL, message.c_str(), "エラー", MB_OK);
#endif // BUILD_DEBUG
	}
}

CANDY_CORE_PROXY_NAMESPACE_END
