/*****************************************************************//**
 * \file   PhysicsCollision2D_TriangleTriangle.h
 * \brief  2D当たり判定(三角形と三角形)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_COLLISION_2D_TRIANGLE_TRIANGLE_H
#define CANDY_PHYSICS_COLLISION_2D_TRIANGLE_TRIANGLE_H

#include <Physics/PhysicsInclude.h>

#include <Physics/Shapde2D/Triangle/PhysicsShape2DTriangle.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace TriangleTriangle
	{
		// 交差判定
		bool Intersect(const Shape2D::Triangle& _triangle1, const Shape2D::Triangle& _triangle2);
	}
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_COLLISION_2D_TRIANGLE_TRIANGLE_H
