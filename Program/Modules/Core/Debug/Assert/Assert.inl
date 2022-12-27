/*****************************************************************//**
 * \file   Assert.inl
 * \brief  アサートの呼び出し
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_DEBUG_ASSERT_INL
#define CANDY_CORE_DEBUG_ASSERT_INL

#include "Assert.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	// アサート呼び出し
	template<typename ...Types>
	void Assert::CallAssert(
		CANDY_UNUSED_VALUE_ATTR const std::string_view _expr, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _fileName, 
		CANDY_UNUSED_VALUE_ATTR const u32 _lineNo,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _funcName, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _format, 
		CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
	{
#if BUILD_DEBUG
		CallAssertDirect(_expr, _fileName, _lineNo, _funcName, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
	}
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_DEBUG_ASSERT_INL
