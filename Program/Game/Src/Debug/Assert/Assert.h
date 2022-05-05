#ifndef CANDY_ASSERT_H
#define CANDY_ASSERT_H

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

#endif // CANDY_ASSERT_H