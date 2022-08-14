/*****************************************************************//**
 * \file   PhysicsShape2DTriangle.cpp
 * \brief  形状定義(2D三角形)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsShape2DTriangle.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	Triangle::Triangle()
	{
		set(ZeroVector, ZeroVector, ZeroVector);
	}

	Triangle::Triangle(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3)
	{
		set(_p1, _p2, _p3);
	}

	// セット
	void Triangle::set(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3)
	{
		m_Points[0] = _p1;
		m_Points[1] = _p2;
		m_Points[2] = _p3;
	}
}

CANDY_PHYSICS_NAMESPACE_END
