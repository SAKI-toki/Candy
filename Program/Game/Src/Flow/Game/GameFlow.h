/*****************************************************************//**
 * \file   GameFlow.h
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_GAME_FLOW_H
#define CANDY_GAME_FLOW_H

#include <GameInclude.h>

namespace GameFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
	// 描画
	void Draw();
}

#endif // CANDY_GAME_FLOW_H
