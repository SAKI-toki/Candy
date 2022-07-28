/*****************************************************************//**
 * \file   DebugDraw.h
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef DEBUG_DRAW_H
#define DEBUG_DRAW_H

#include <App/AppInclude.h>

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

	// 文字列登録(位置)
	void DrawString(const Vec4 _pos, const char* const _format, ...);
	// 文字列登録(位置, 色)
	void DrawString(const Vec4 _pos, const Color _color, const char* const _format, ...);
	// 文字列登録(位置, 色, サイズ)
	void DrawString(const Vec4 _pos, const Color _color, const f32 _scale, const char* const _format, ...);
}

CANDY_APP_NAMESPACE_END

#endif // DEBUG_DRAW_H
