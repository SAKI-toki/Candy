/*****************************************************************//**
 * \file   Assert.h
 * \brief  アサートの呼び出し
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_ASSERT_H
#define CANDY_DEBUG_ASSERT_H

#if PLATFORM_WIN
#include "Platform/Win/AssertImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

#if BUILD_DEBUG
#define CANDY_ASSERT(EXPR) if(!(EXPR)) assertImpl(#EXPR, __FILE__, __LINE__, __func__)
#else
#define CANDY_ASSERT(EXPR) dummyFunc(EXPR)
#endif // BUILD_DEBUG


CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_ASSERT_H
