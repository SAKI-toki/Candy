/*****************************************************************//**
 * \file   PhysicsShape2DRay.h
 * \brief  形状定義(2Dレイ)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_PHYSICS_SHAPE2D_RAY_H
#define CANDY_PHYSICS_SHAPE2D_RAY_H

#include <Physics/PhysicsInclude.h>

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Shape2D
{
	struct Ray
	{
	public:
		Ray();
		Ray(const Vec4 _begin, const Vec4 _end);

		// セット
		void set(const Vec4 _begin, const Vec4 _end);

		// 長さ取得
		f32 getLength()const;
		// 長さ取得(二乗)
		f32 getLengthSqr()const;

		// 向きを取得
		Vec4 getDir()const;
		// 向きを取得(Normalize)
		Vec4 getDirNormalize()const;

		Vec4 m_Begin;
		Vec4 m_End;
	};
}

CANDY_PHYSICS_NAMESPACE_END

#endif // CANDY_PHYSICS_SHAPE2D_RAY_H
