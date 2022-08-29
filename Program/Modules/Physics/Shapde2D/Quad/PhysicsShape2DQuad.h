/*****************************************************************//**
 * \file   PhysicsShape2DQuad.h
 * \brief  形状定義(2Dクアッド)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_SHAPE2D_QUAD_H
#define CANDY_PHYSICS_SHAPE2D_QUAD_H

#include <Physics/PhysicsInclude.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	struct Quad
	{
	public:
		Quad();
		Quad(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3, const Vec4 _p4);
		Quad(const Rect& _rect);

		// セット
		void set(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3, const Vec4 _p4);
		// 矩形セット
		void setRect(const Rect& _rect);

		// へこんでいる頂点のインデックス取得
		std::optional<s32> getConcavePointIndex()const;

		Vec4 m_Points[4];
	};
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_SHAPE2D_QUAD_H
