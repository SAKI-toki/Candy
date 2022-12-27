/*****************************************************************//**
 * \file   Assert.h
 * \brief  アサートの呼び出し
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_DEBUG_ASSERT_H
#define CANDY_CORE_DEBUG_ASSERT_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Debug/Assert/AssertImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	namespace Assert
	{
		// アサート呼び出し
		template<typename ...Types>
		void CallAssert(const std::string_view _expr, const std::string_view _fileName, const u32 _lineNo, 
			const std::string_view _funcName, const std::string_view _format, Types&& ..._args);

		void CallAssertDirect(const std::string_view _expr, const std::string_view _fileName, const u32 _lineNo,
			const std::string_view _funcName, const std::string_view _msg);
	}
}

#if BUILD_DEBUG
#define CANDY_ASSERT(EXPR) if(!(EXPR)) candy::core::Debug::Assert::CallAssert(#EXPR, __FILE__, __LINE__, __func__,  "")
#define CANDY_ASSERT_MSG(EXPR, MESSAGE_FMT, ...) if(!(EXPR)) candy::core::Debug::Assert::CallAssert(#EXPR, __FILE__, __LINE__, __func__, (MESSAGE_FMT), __VA_ARGS__)
#else
#define CANDY_ASSERT(EXPR) (EXPR)
#define CANDY_ASSERT_MSG(EXPR, ...) (EXPR)
#endif // BUILD_DEBUG

CANDY_CORE_NAMESPACE_END

#include "Assert.inl"

#endif // CANDY_CORE_DEBUG_ASSERT_H
