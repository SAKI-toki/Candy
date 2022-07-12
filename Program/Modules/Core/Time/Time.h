/*****************************************************************//**
 * \file   Time.h
 * \brief  時間
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TIME_H
#define CANDY_CORE_TIME_H

#include <Core/CoreInclude.h>

#include "Tick.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Time
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// ティック取得
	Tick GetTick();
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_TIME_H
