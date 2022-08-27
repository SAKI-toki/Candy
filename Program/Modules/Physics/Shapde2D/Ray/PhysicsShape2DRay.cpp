/*****************************************************************//**
 * \file   PhysicsShape2DRay.cpp
 * \brief  形状定義(2Dレイ)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsShape2DRay.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	Ray::Ray()
	{
		set(ZeroVector, ZeroVector);
	}

	Ray::Ray(const Vec4 _begin, const Vec4 _end)
	{
		set(_begin, _end);
	}

	// セット
	void Ray::set(const Vec4 _begin, const Vec4 _end)
	{
		m_Begin = _begin;
		m_End = _end;
	}

	// 長さ取得
	f32 Ray::getLength()const
	{
		return VecDist(m_Begin, m_End);
	}
	// 長さ取得(二乗)
	f32 Ray::getLengthSqr()const
	{
		return VecDistSqr(m_Begin, m_End);
	}

	// 向きを取得
	Vec4 Ray::getDir()const
	{
		return m_End - m_Begin;
	}

	// 向きを取得(Normalize)
	Vec4 Ray::getDirNormalize()const
	{
		return VecNormalize(getDir());
	}
}

CANDY_PHYSICS_NAMESPACE_END
