/*****************************************************************//**
 * \file   DebugDraw.h
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef DEBUG_DRAW_H
#define DEBUG_DRAW_H

#include <App/AppInclude.h>

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

	// 文字列登録
	template<typename ...Types>
	void DrawString(const String::AddInfo& _addInfo, const std::string_view _format, Types&& ..._args);
	// 文字列登録(位置)
	template<typename ...Types>
	void DrawString(const Vec4 _pos, const std::string_view _format, Types&& ..._args);
	// 文字列登録(位置, 色)
	template<typename ...Types>
	void DrawString(const Vec4 _pos, const Color _color, const std::string_view _format, Types&& ..._args);
	// 文字列登録(位置, 色, サイズ)
	template<typename ...Types>
	void DrawString(const Vec4 _pos, const Color _color, const f32 _scale, const std::string_view _format, Types&& ..._args);
}

CANDY_APP_NAMESPACE_END

#include "DebugDraw.inl"

#endif // DEBUG_DRAW_H
