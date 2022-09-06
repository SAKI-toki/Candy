﻿/*****************************************************************//**
 * \file   DebugDrawPrimitive2D.h
 * \brief  2Dプリミティブのデバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_DRAW_PRIMITIVE_2D_H
#define CANDY_DEBUG_DRAW_PRIMITIVE_2D_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw::Primitive2D
{
	struct VertexInfo
	{
		VertexInfo() = default;
		VertexInfo(const Vec4 _pos, const Color _color) :m_Pos{ _pos }, m_Color{ _color } {}
		Vec4 m_Pos;
		Color m_Color;
	};

	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();
	// 描画
	void Draw();

	// 2D三角形の描画登録
	void AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Color _color);
	void AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3,
		const Color _color1, const Color _color2, const Color _color3);
	void AddTriangle2D(const VertexInfo(&_vertices)[3]);

	// 2Dクアッドの描画登録
	void AddQuad2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4, const Color _color);
	void AddQuad2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4,
		const Color _color1, const Color _color2, const Color _color3, const Color _color4);
	void AddQuad2D(const VertexInfo(&_vertices)[4]);

	// 2D矩形の描画登録
	void AddRect2D(const Rect _rect, const Color _color);
	void AddRect2D(const Rect _rect, const Color _color1, const Color _color2, const Color _color3, const Color _color4);
	void AddRect2D(const VertexInfo(&_vertices)[4]);

	// 2D線分の描画登録
	void AddLine2D(const Vec4 _begin, const Vec4 _end, const f32 _width, const Color _color);
	void AddLine2D(const VertexInfo(&_vertices)[4]);

	// 2Dの描画登録
	void Add2D(const VertexInfo* const _vertices, const s32 _vertexCount, const u16* const _indices, const s32 _indexCount);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_PRIMITIVE_2D_H
