/*****************************************************************//**
 * \file   SceneFlow.h
 * \brief  シーンフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_SCENE_FLOW_H
#define CANDY_SCENE_FLOW_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace SceneFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_SCENE_FLOW_H
