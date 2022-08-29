/*****************************************************************//**
 * \file   PhysicsCollision2D_RayCast.cpp
 * \brief  2D当たり判定(レイキャスト)
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "PhysicsCollision2D_RayCast.h"

CANDY_PHYSICS_NAMESPACE_BEGIN

namespace Collision2D
{
	namespace RayCast::Impl
	{
		// 四角形に対するレイキャストの実装部
		std::optional<types::RayCastHitInfo2D> ToQuadImpl(const Shape2D::Ray& _ray, const Shape2D::Quad& _quad,
			std::function<s32(const s32 _index0)>&& _getInsideVecDotIndexFunc)
		{
			std::optional<types::RayCastHitInfo2D> hitInfo;

			for (s32 i = 0; i < 4; ++i)
			{
				const s32 index0 = i;
				const s32 index1 = core::LoopSize(index0 + 1, 0, 4);

				Shape2D::Line line{ _quad.m_Points[index1], _quad.m_Points[index0] };
				auto result = ToLine(_ray, line);
				if (!result)continue;

				if (hitInfo && hitInfo.value().m_DistSqr < result.value().m_DistSqr)continue;

				// 内外判定
				const s32 insideVecDotIndex = _getInsideVecDotIndexFunc(index0);
				f32 dot = VecDot(result.value().m_Normal, result.value().m_Pos - _quad.m_Points[insideVecDotIndex]);
				if (dot <= 0)continue;

				hitInfo = result;
			}

			return hitInfo;
		}
	}

	// ラインに対するレイキャスト
	std::optional<types::RayCastHitInfo2D> RayCast::ToLine(const Shape2D::Ray& _ray, const Shape2D::Line& _line)
	{
		const Vec4 rayDirNorm = _ray.getDirNormalize();
		const Vec4 lineDirNorm = _line.getDirNormalize();

		if (rayDirNorm == lineDirNorm)return std::nullopt;

		const Vec4 rayDir = _ray.getDir().getXY();
		const Vec4 lineDir = _line.getDir().getXY();

		const Vec4 ab = rayDir;
		const Vec4 cd = lineDir;
		const Vec4 ac = (_line.m_Begin - _ray.m_Begin).getXY();
		const Vec4 ca = ac * -1.0f;

		const f32 crossAcCd = VecCross(ac, cd).z;
		const f32 crossAbCd = VecCross(ab, cd).z;
		const f32 crossCaAb = VecCross(ca, ab).z;
		const f32 crossCdAb = crossAbCd * -1.0f;

		const f32 s = crossAcCd / crossAbCd;
		const f32 t = crossCaAb / crossCdAb;

		if (s < 0.0f || s > 1.0f || t < 0.0f || t > 1.0f)return std::nullopt;
		
		types::RayCastHitInfo2D hitInfo;

		hitInfo.m_Pos = _ray.m_Begin + rayDir * s;

		Vec4 lineNormal = Vec4{ -lineDir.y , lineDir.x, 0.0f };
		if (VecDot(lineNormal, rayDir) > 0)
		{
			lineNormal = Vec4{ lineDir.y , -lineDir.x, 0.0f };
		}
		hitInfo.m_Normal = VecNormalize(lineNormal);
		hitInfo.m_DistSqr = VecDistSqr(hitInfo.m_Pos, _ray.m_Begin);

		return hitInfo;
	}

	// 三角形に対するレイキャスト
	std::optional<types::RayCastHitInfo2D> RayCast::ToTriangle(const Shape2D::Ray& _ray, const Shape2D::Triangle& _triangle)
	{
		for (s32 i = 0; i < 3; ++i)
		{
			const s32 index0 = i;
			const s32 index1 = core::LoopSize(index0 + 1, 0, 3);
			const s32 index2 = core::LoopSize(index1 + 1, 0, 3);

			Shape2D::Line line{ _triangle.m_Points[index1], _triangle.m_Points[index0] };
			auto result = ToLine(_ray, line);
			if (!result)continue;

			// 内外判定
			f32 dot = VecDot(result.value().m_Normal, result.value().m_Pos - _triangle.m_Points[index2]);
			if (dot > 0)
			{
				return result;
			}
		}
		return std::nullopt;
	}

	// 凹みなし四角形に対するレイキャスト
	std::optional<types::RayCastHitInfo2D> RayCast::ToConvexQuad(const Shape2D::Ray& _ray, const Shape2D::Quad& _quad)
	{
		return Impl::ToQuadImpl(_ray, _quad, 
			[]( const s32 _index0)
			{
				return core::LoopSizeStrictInt(_index0 + 2, 0, 4);
			});
	}

	// 凹みあり四角形に対するレイキャスト
	std::optional<types::RayCastHitInfo2D> RayCast::ToConcaveQuad(const Shape2D::Ray& _ray, const Shape2D::Quad& _quad)
	{
		auto concavePointIndex = _quad.getConcavePointIndex();
		if (!concavePointIndex)return ToConvexQuad(_ray, _quad);

		const s32 concavePointIndexValue = concavePointIndex.value();
		const s32 diagonalConcavePointIndex = core::LoopSizeStrictInt(concavePointIndexValue + 2, 0, 4);

		return Impl::ToQuadImpl(_ray, _quad, 
			[concavePointIndexValue, diagonalConcavePointIndex](const s32 _index0)
			{
				const s32 index1 = core::LoopSize(_index0 + 1, 0, 4);
				const s32 index2 = core::LoopSize(index1 + 1, 0, 4);

				// 判定ラインで凹み頂点を使っている場合は凹み頂点の対頂点で内外判定する
				if (_index0 == concavePointIndexValue || index1 == concavePointIndexValue)
				{
					return diagonalConcavePointIndex;
				}
				else
				{
					return index2;
				}
			});
	}
}

CANDY_PHYSICS_NAMESPACE_END
