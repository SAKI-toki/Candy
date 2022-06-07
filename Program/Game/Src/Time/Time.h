/*****************************************************************//**
 * \file   Time.h
 * \brief  時間
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_TIME_H
#define CANDY_TIME_H

#include "Tick.h"

CANDY_NAMESPACE_BEGIN

namespace Time
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// ティック取得
	Tick GetTick();
}

CANDY_NAMESPACE_END

#endif // CANDY_TIME_H
