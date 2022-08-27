/*****************************************************************//**
 * \file   PhysicsCollision2D_RayCast.h
 * \brief  2D当たり判定(レイキャスト)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_COLLISION_2D_RAY_CAST_H
#define CANDY_PHYSICS_COLLISION_2D_RAY_CAST_H

#include <Physics/PhysicsInclude.h>

#include <Physics/Shapde2D/Ray/PhysicsShape2DRay.h>
#include <Physics/Shapde2D/Line/PhysicsShape2DLine.h>
#include <Physics/Shapde2D/Triangle/PhysicsShape2DTriangle.h>
#include <Physics/Shapde2D/Quad/PhysicsShape2DQuad.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace RayCast
	{
		// ラインに対するレイキャスト
		std::optional<types::RayCastHitInfo2D> ToLine(const Shape2D::Ray& _ray, const Shape2D::Line& _line);

		// 三角形に対するレイキャスト
		std::optional<types::RayCastHitInfo2D> ToTriangle(const Shape2D::Ray& _ray, const Shape2D::Triangle& _triangle);

		// 凹みなし四角形に対するレイキャスト
		std::optional<types::RayCastHitInfo2D> ToConvexQuad(const Shape2D::Ray& _ray, const Shape2D::Quad& _quad);

		// 凹みあり四角形に対するレイキャスト
		std::optional<types::RayCastHitInfo2D> ToConcaveQuad(const Shape2D::Ray& _ray, const Shape2D::Quad& _quad);
	}
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_COLLISION_2D_RAY_CAST_H
