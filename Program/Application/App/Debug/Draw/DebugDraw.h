/*****************************************************************//**
 * \file   DebugDraw.h
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef DEBUG_DRAW_H
#define DEBUG_DRAW_H

#include <App/AppInclude.h>
#include "Primitive2D/DebugDrawPrimitive2D.h"
#include "String/DebugDrawString.h"

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw
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

#endif // DEBUG_DRAW_H
