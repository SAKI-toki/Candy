/*****************************************************************//**
 * \file   PhysicsCollision2D_TriangleTriangle.cpp
 * \brief  2D当たり判定(三角形と三角形)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsCollision2D_TriangleTriangle.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace TriangleTriangle
	{
		// 交差判定の実装部
		bool IntersectImpl(const Shape2D::Triangle& _triangle1, const Shape2D::Triangle& _triangle2)
		{
			for (s32 i = 0; i < 3; ++i)
			{
				const s32 index1 = i;
				const s32 index2 = core::LoopSize(index1 + 1, 0, 3);
				const s32 index3 = core::LoopSize(index2 + 1, 0, 3);

				// 辺の法線ベクトル
				Vec4 lineNormal = _triangle1.m_Points[index1] - _triangle1.m_Points[index2];
				std::swap(lineNormal.x, lineNormal.y);
				lineNormal.x = -lineNormal.x;
				lineNormal = VecNormalize(lineNormal);

				f32 pos1_1 = VecDot(lineNormal, _triangle1.m_Points[index2]);
				f32 pos1_2 = VecDot(lineNormal, _triangle1.m_Points[index3]);

				f32 pos2_1 = VecDot(lineNormal, _triangle2.m_Points[index1]);
				f32 pos2_2 = VecDot(lineNormal, _triangle2.m_Points[index2]);
				f32 pos2_3 = VecDot(lineNormal, _triangle2.m_Points[index3]);

				f32 pos1Min = core::Min(pos1_1, pos1_2);
				f32 pos1Max = core::Max(pos1_1, pos1_2);

				f32 pos2Min = core::Min(pos2_1, pos2_2, pos2_3);
				f32 pos2Max = core::Max(pos2_1, pos2_2, pos2_3);

				// 分離軸があるか
				if (pos1Min > pos2Max || pos1Max < pos2Min)return false;
			}
			return true;
		}
	}

	// 交差判定
	bool TriangleTriangle::Intersect(const Shape2D::Triangle& _triangle1, const Shape2D::Triangle& _triangle2)
	{
		return IntersectImpl(_triangle1, _triangle2) && IntersectImpl(_triangle2, _triangle1);
	}
}

CANDY_PHYSICS_NAMESPACE_END
