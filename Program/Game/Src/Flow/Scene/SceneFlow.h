/*****************************************************************//**
 * \file   SceneFlow.h
 * \brief  シーンフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_SCENE_FLOW_H
#define CANDY_SCENE_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace SceneFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
}

CANDY_NAMESPACE_END

#endif // CANDY_SCENE_FLOW_H
