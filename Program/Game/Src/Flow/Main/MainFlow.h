/*****************************************************************//**
 * \file   MainFlow.h
 * \brief  メインフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_MAIN_FLOW_H
#define CANDY_MAIN_FLOW_H

#include <GameInclude.h>

namespace MainFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// 終了判定
	bool IsEnd();
}

#endif // CANDY_MAIN_FLOW_H
