#ifndef CANDY_VEC4_H
#define CANDY_VEC4_H

#if PLATFORM_WIN
#include "Platform/Win/Vec4Impl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

using Vec4 = Vec4Impl;

inline const Vec4 ZeroVector	= Vec4{  0.0f,  0.0f,  0.0f };
inline const Vec4 RightVector	= Vec4{  1.0f,  0.0f,  0.0f };
inline const Vec4 LeftVector	= Vec4{ -1.0f,  0.0f,  0.0f };
inline const Vec4 UpVector		= Vec4{  0.0f,  1.0f,  0.0f };
inline const Vec4 DownVector	= Vec4{  0.0f, -1.0f,  0.0f };
inline const Vec4 FrontVector	= Vec4{  0.0f,  0.0f,  1.0f };
inline const Vec4 BackVector	= Vec4{  0.0f,  0.0f, -1.0f };

CANDY_NAMESPACE_END

#endif // CANDY_VEC4_H
