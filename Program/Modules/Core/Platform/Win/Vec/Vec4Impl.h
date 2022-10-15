/*****************************************************************//**
 * \file   Vec4Impl.h
 * \brief  Vector4の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_IMPL_H
#define CANDY_CORE_VEC4_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

struct alignas(16) Vec4Impl
{
	Vec4Impl();
	Vec4Impl(const vector_type _v);

	Vec4Impl(const Vec4Impl& _other);
	Vec4Impl(Vec4Impl&& _other)noexcept;
	void copy(const Vec4Impl& _other);
	void move(Vec4Impl&& _other)noexcept;

	union
	{
		struct
		{
			f32 x, y, z, w;
		};
		struct
		{
			f32 r, g, b, a;
		};
		
		f32 m_f32Array[4];

		vector_type vector;
	};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_IMPL_H
