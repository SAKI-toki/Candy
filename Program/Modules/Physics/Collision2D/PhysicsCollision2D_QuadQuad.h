/*****************************************************************//**
 * \file   PhysicsCollision2D_QuadQuad.h
 * \brief  2D当たり判定(クアッドとクアッド)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_COLLISION_2D_QUAD_QUAD_H
#define CANDY_PHYSICS_COLLISION_2D_QUAD_QUAD_H

#include <Physics/PhysicsInclude.h>

#include <Physics/Shapde2D/Quad/PhysicsShape2DQuad.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace QuadQuad
	{
		// 凹みなし交差判定
		bool IntersectConvex(const Shape2D::Quad& _quad1, const Shape2D::Quad& _quad2);

		// 凹みあり交差判定
		bool IntersectConcave(const Shape2D::Quad& _quad1, const Shape2D::Quad& _quad2);
	}
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_COLLISION_2D_QUAD_QUAD_H
