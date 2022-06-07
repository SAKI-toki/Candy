﻿/*****************************************************************//**
 * \file   Platform.h
 * \brief  プラットフォーム定義
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_PLATFORM_H
#define CANDY_PLATFORM_H

CANDY_NAMESPACE_BEGIN

#define PLATFORM_WIN 0

#if _WIN64
#undef PLATFORM_WIN
#define PLATFORM_WIN 1
#elif _WIN32
#undef PLATFORM_WIN
#define PLATFORM_WIN 1
#endif

CANDY_NAMESPACE_END

#if PLATFORM_WIN
#include "Win/PlatformImpl.h"
#endif // PLATFORM_WIN

#endif // CANDY_PLATFORM_H
