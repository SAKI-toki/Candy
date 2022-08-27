/*****************************************************************//**
 * \file   PhysicsCollision2DTypes.h
 * \brief  2D当たり判定関連のタイプ
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_COLLISION_2D_TYPES_H
#define CANDY_PHYSICS_COLLISION_2D_TYPES_H

#include <Physics/PhysicsInclude.h>

#include <Physics/Shapde2D/Triangle/PhysicsShape2DTriangle.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace types
{
	struct RayCastHitInfo2D
	{
		Vec4 m_Pos{};
		Vec4 m_Normal{};
		f32 m_DistSqr{};
	};
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_COLLISION_2D_TYPES_H
