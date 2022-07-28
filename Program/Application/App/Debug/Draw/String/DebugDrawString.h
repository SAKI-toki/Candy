/*****************************************************************//**
 * \file   DebugDrawString.h
 * \brief  文字列のデバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_DRAW_STRING_H
#define CANDY_DEBUG_DRAW_STRING_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw::String
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
	// 描画
	void Draw();
	
	// 描画登録(位置)
	void Add(const Vec4 _pos, const std::string& _str);
	// 描画登録(位置, 色)
	void Add(const Vec4 _pos, const Color _color, const std::string& _str);
	// 描画登録(位置, 色, サイズ)
	void Add(const Vec4 _pos, const Color _color, const f32 _scale, const std::string& _str);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_STRING_H
