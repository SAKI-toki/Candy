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
	// 交差判定
	bool QuadQuad::Intersect(const Shape2D::Quad& _quad1, const Shape2D::Quad& _quad2)
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
}

CANDY_PHYSICS_NAMESPACE_END
