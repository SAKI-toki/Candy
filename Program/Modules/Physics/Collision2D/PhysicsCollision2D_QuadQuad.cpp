/*****************************************************************//**
 * \file   PhysicsCollision2D_QuadQuad.cpp
 * \brief  2D当たり判定(クアッドとクアッド)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsCollision2D_QuadQuad.h"
#include "PhysicsCollision2D_TriangleTriangle.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace QuadQuad::Impl
	{
		// 凹みありの四角形から三角形を取得
		std::pair<Shape2D::Triangle, Shape2D::Triangle> getTriangleFromConcaveQuad(const Shape2D::Quad& _quad)
		{
			s32 index0 = 0;
			s32 index1 = 1;
			s32 index2 = 2;
			s32 index3 = 3;

			if (auto concavePointIndex = _quad.getConcavePointIndex())
			{
				index0 = concavePointIndex.value();
				index1 = core::LoopSize(index0 + 1, 0, 4);
				index2 = core::LoopSize(index1 + 1, 0, 4);
				index3 = core::LoopSize(index2 + 1, 0, 4);
			}

			return std::make_pair(
				Shape2D::Triangle{ _quad.m_Points[index0], _quad.m_Points[index1], _quad.m_Points[index2] },
				Shape2D::Triangle{ _quad.m_Points[index0], _quad.m_Points[index2], _quad.m_Points[index3] });
		}
	}

	// 凹みなし交差判定
	bool QuadQuad::IntersectConvex(const Shape2D::Quad& _quad1, const Shape2D::Quad& _quad2)
	{
		Shape2D::Triangle triangle1_1{ _quad1.m_Points[0], _quad1.m_Points[1], _quad1.m_Points[3] };
		Shape2D::Triangle triangle1_2{ _quad1.m_Points[1], _quad1.m_Points[2], _quad1.m_Points[3] };
		Shape2D::Triangle triangle2_1{ _quad2.m_Points[0], _quad2.m_Points[1], _quad2.m_Points[3] };
		Shape2D::Triangle triangle2_2{ _quad2.m_Points[1], _quad2.m_Points[2], _quad2.m_Points[3] };

		return TriangleTriangle::Intersect(triangle1_1, triangle2_1) ||
			TriangleTriangle::Intersect(triangle1_1, triangle2_2) ||
			TriangleTriangle::Intersect(triangle1_2, triangle2_1) ||
			TriangleTriangle::Intersect(triangle1_2, triangle2_2);
	}

	// 凹みあり交差判定
	bool QuadQuad::IntersectConcave(const Shape2D::Quad& _quad1, const Shape2D::Quad& _quad2)
	{
		auto triangles1 = Impl::getTriangleFromConcaveQuad(_quad1);
		auto triangles2 = Impl::getTriangleFromConcaveQuad(_quad2);
		
		return TriangleTriangle::Intersect(triangles1.first, triangles2.first) ||
			TriangleTriangle::Intersect(triangles1.first, triangles2.second) ||
			TriangleTriangle::Intersect(triangles1.second, triangles2.first) ||
			TriangleTriangle::Intersect(triangles1.second, triangles2.second);
	}
}

CANDY_PHYSICS_NAMESPACE_END
