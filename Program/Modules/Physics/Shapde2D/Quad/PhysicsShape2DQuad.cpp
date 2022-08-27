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

	// へこんでいる頂点のインデックス取得
	std::optional<s32> Quad::getConcavePointIndex()const
	{
		// 凹んでいる頂点の場所ならカウントが2になる
		std::array<s32, 4> concaveCheckCounts{};

		for (s32 i = 0; i < 4; ++i)
		{
			const s32 index0 = i;
			const s32 index1 = core::LoopSize(index0 + 1, 0, 4);
			const s32 index2 = core::LoopSize(index1 + 1, 0, 4);
			const s32 index3 = core::LoopSize(index2 + 1, 0, 4);

			const Vec4 testBaseVec = m_Points[index0] - m_Points[index1];
			const Vec4 testVec1 = m_Points[index0] - m_Points[index2];
			const Vec4 testVec2 = m_Points[index0] - m_Points[index3];

			s32 sign1 = core::Sign(VecCross(testBaseVec, testVec1).z);
			s32 sign2 = core::Sign(VecCross(testBaseVec, testVec2).z);
			if (sign1 == sign2)continue;

			++concaveCheckCounts[index0];
			++concaveCheckCounts[index1];

			if (concaveCheckCounts[index0] >= 2)return index0;
			if (concaveCheckCounts[index1] >= 2)return index1;
		}

		return std::nullopt;
	}
}

CANDY_PHYSICS_NAMESPACE_END
