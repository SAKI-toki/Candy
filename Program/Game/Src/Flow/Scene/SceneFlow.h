/*****************************************************************//**
 * \file   SceneFlow.h
 * \brief  シーンフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_SCENE_FLOW_H
#define CANDY_SCENE_FLOW_H

#include <GameInclude.h>

namespace SceneFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
}

#endif // CANDY_SCENE_FLOW_H
