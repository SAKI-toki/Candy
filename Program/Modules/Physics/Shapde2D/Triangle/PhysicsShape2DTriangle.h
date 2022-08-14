/*****************************************************************//**
 * \file   PhysicsShape2DTriangle.h
 * \brief  形状定義(2D三角形)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_SHAPE2D_TRIANGLE_H
#define CANDY_PHYSICS_SHAPE2D_TRIANGLE_H

#include <Physics/PhysicsInclude.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	struct Triangle
	{
	public:
		Triangle();
		Triangle(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3);

		// セット
		void set(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3);

		Vec4 m_Points[3];
	};
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_SHAPE2D_TRIANGLE_H
