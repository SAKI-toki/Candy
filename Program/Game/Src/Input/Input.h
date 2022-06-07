/*****************************************************************//**
 * \file   Input.h
 * \brief  入力
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_H
#define CANDY_INPUT_H

CANDY_NAMESPACE_BEGIN

namespace Input
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// キー入力開始判定
	bool IsKeyTrigger(const u8 _key);
	// キー入力判定
	bool IsKeyOn(const u8 _key);
	// キー入力終了判定
	bool IsKeyRelease(const u8 _key);
	// キー入力判定(一定間隔)
	bool IsKeyRepeat(const u8 _key);

	// マウスのPC画面上の位置取得
	Vec4 GetScreenMousePos();
	// マウスのアプリ画面上の位置取得
	Vec4 GetClientMousePos();
	// マウスのPC画面上の1フレ前位置取得
	Vec4 GetPrevScreenMousePos();
	// マウスのアプリ画面上の1フレ前位置取得
	Vec4 GetPrevClientMousePos();
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_H
