#ifndef CANDY_VEC4_H
#define CANDY_VEC4_H

#if PLATFORM_WIN
#include "Platform/Win/Vec4Impl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

using Vec4 = Vec4Impl;

CANDY_NAMESPACE_END

#endif // CANDY_VEC4_H
