/*****************************************************************//**
 * \file   Debug.h
 * \brief  デバッグ関連
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_H
#define CANDY_DEBUG_H

#include <GameInclude.h>

namespace Debug
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

#endif // CANDY_DEBUG_H
