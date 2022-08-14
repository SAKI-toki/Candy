/*****************************************************************//**
 * \file   PhysicsShape2DQuad.cpp
 * \brief  形状定義(2Dクアッド)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsShape2DQuad.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	Quad::Quad()
	{
		set(ZeroVector, ZeroVector, ZeroVector, ZeroVector);
	}

	Quad::Quad(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3, const Vec4 _p4)
	{
		set(_p1, _p2, _p3, _p4);
	}

	// セット
	void Quad::set(const Vec4 _p1, const Vec4 _p2, const Vec4 _p3, const Vec4 _p4)
	{
		m_Points[0] = _p1;
		m_Points[1] = _p2;
		m_Points[2] = _p3;
		m_Points[3] = _p4;
	}
}

CANDY_PHYSICS_NAMESPACE_END
