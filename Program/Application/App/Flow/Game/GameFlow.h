/*****************************************************************//**
 * \file   GameFlow.h
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_GAME_FLOW_H
#define CANDY_GAME_FLOW_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

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

CANDY_APP_NAMESPACE_END

#endif // CANDY_GAME_FLOW_H
