/*****************************************************************//**
 * \file   MtxImpl.h
 * \brief  Matrixの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MATRIX_IMPL_H
#define CANDY_CORE_MATRIX_IMPL_H

#include <Core/CoreInclude.h>
#include <Core/Vec/Vec4.h>
#include <DirectXMath.h>

CANDY_CORE_NAMESPACE_BEGIN

struct alignas(16) MtxImpl
{
	MtxImpl();

	MtxImpl(const MtxImpl&);
	MtxImpl(MtxImpl&&)noexcept;
	void copy(const MtxImpl& _other);
	void move(MtxImpl&& _other)noexcept;

	union
	{
        struct
        {
            f32 _11, _12, _13, _14;
            f32 _21, _22, _23, _24;
            f32 _31, _32, _33, _34;
            f32 _41, _42, _43, _44;
        };

		vector_type vector[4];
		
		Vec4 vec4[4];
	};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MATRIX_IMPL_H
