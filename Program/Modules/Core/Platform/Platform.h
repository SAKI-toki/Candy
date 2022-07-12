/*****************************************************************//**
 * \file   Platform.h
 * \brief  プラットフォーム定義
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_PLATFORM_H
#define CANDY_CORE_PLATFORM_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

#define PLATFORM_WIN 0

#if _WIN64
#undef PLATFORM_WIN
#define PLATFORM_WIN 1
#elif _WIN32
#undef PLATFORM_WIN
#define PLATFORM_WIN 1
#endif

CANDY_CORE_NAMESPACE_END

#if PLATFORM_WIN
#include "Win/PlatformImpl.h"
#endif // PLATFORM_WIN

#endif // CANDY_CORE_PLATFORM_H
