/*****************************************************************//**
 * \file   Vec4Impl.cpp
 * \brief  Vector4の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Vec4Impl.h"

CANDY_CORE_NAMESPACE_BEGIN

Vec4Impl::Vec4Impl()
{

}

Vec4Impl::Vec4Impl(const vector_type _v) : vector{ _v }
{
	
}

Vec4Impl::Vec4Impl(const Vec4Impl& _other) : vector{ _other.vector }
{

}
Vec4Impl::Vec4Impl(Vec4Impl&& _other)noexcept : vector{ std::move(_other.vector) }
{

}

void Vec4Impl::copy(const Vec4Impl& _other)
{
	vector = _other.vector;
}

void Vec4Impl::move(Vec4Impl&& _other)noexcept
{
	vector = std::move(_other.vector);
}

CANDY_CORE_NAMESPACE_END
