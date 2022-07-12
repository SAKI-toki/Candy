/*****************************************************************//**
 * \file   Global.h
 * \brief  グローバルなパラメータ群
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_GLOBAL_H
#define CANDY_GLOBAL_H

#include <GameInclude.h>

namespace Global
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
	// フリップ
	void Flip();

	// 前フレームの経過時間の取得
	f32 GetAppTime();
	// トータルのフレームの経過時間の取得
	f32 GetAppTimeAll();

	// 更新インデックス
	s32 GetUpdateIndex();
	// 描画インデックス
	s32 GetDrawIndex();
}

#endif // CANDY_GLOBAL_H
