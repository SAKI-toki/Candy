﻿/*****************************************************************//**
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
	Vec4Impl(const __m128 _v);

	Vec4Impl(const Vec4Impl&);
	Vec4Impl& operator=(const Vec4Impl&);
	Vec4Impl(Vec4Impl&&)noexcept;
	Vec4Impl& operator=(Vec4Impl&&)noexcept;

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

		__m128 m128;
	};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_VEC4_IMPL_H
