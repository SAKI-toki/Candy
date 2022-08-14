/*****************************************************************//**
 * \file   PhysicsCollision2D_LineLine.h
 * \brief  2D当たり判定(ラインとライン)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_COLLISION_2D_LINE_LINE_H
#define CANDY_PHYSICS_COLLISION_2D_LINE_LINE_H

#include <Physics/PhysicsInclude.h>

#include <Physics/Shapde2D/Line/PhysicsShape2DLine.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace LineLine
	{
		// 交差判定
		bool Intersect(const Shape2D::Line& _line1, const Shape2D::Line& _line2);
	}
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_COLLISION_2D_LINE_LINE_H
