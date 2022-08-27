/*****************************************************************//**
 * \file   PhysicsCollision2D_LineLine.cpp
 * \brief  2D当たり判定(ラインとライン)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsCollision2D_LineLine.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace LineLine::Impl
	{
		// 外積による交差判定の実装部
		bool IntersectImplCross(const Shape2D::Line& _line1, const Shape2D::Line& _line2)
		{
			const Vec4 dirBase = _line1.getDir();
			const Vec4 dir1 = (_line1.m_Begin - _line2.m_Begin);
			const Vec4 dir2 = (_line1.m_Begin - _line2.m_End);

			const s32 sign1 = core::Sign(VecCross(dirBase, dir1).z);
			const s32 sign2 = core::Sign(VecCross(dirBase, dir2).z);
			return sign1 != sign2;
		}
	}

	// 交差判定
	bool LineLine::Intersect(const Shape2D::Line& _line1, const Shape2D::Line& _line2)
	{
		return Impl::IntersectImplCross(_line1, _line2) && Impl::IntersectImplCross(_line2, _line1);
	}
}

CANDY_PHYSICS_NAMESPACE_END
