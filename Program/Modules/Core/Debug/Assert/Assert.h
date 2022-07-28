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
		void CallAssert(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName);
	}
}

#if BUILD_DEBUG
#define CANDY_ASSERT(EXPR) if(!(EXPR)) candy::core::Debug::Assert::CallAssert(#EXPR, __FILE__, __LINE__, __func__)
#else
#define CANDY_ASSERT(EXPR) dummyFunc(EXPR)
#endif // BUILD_DEBUG

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_DEBUG_ASSERT_H
