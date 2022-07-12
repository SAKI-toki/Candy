/*****************************************************************//**
 * \file   Time.cpp
 * \brief  時間
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#include "Time.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Time/TimeImpl.h>
#endif

CANDY_CORE_NAMESPACE_BEGIN

// 初期化
void Time::Startup()
{
	Impl::Startup();
}
// 破棄
void Time::Cleanup()
{
	Impl::Cleanup();
}

// ティック取得
Tick Time::GetTick()
{
	return Tick{};
}

CANDY_CORE_NAMESPACE_END
