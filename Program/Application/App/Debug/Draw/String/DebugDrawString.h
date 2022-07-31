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
	
	struct AddInfo
	{
		Vec4 m_Pos{};
		Color m_Color{ 0.0f, 0.0f, 0.0f };
		f32 m_Scale{ 20.0f };
	};

	// 描画登録
	void Add(const AddInfo& _addInfo, const std::string_view _format);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_STRING_H
