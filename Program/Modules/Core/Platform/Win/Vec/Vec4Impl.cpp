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

Vec4Impl::Vec4Impl(const __m128 _v) : m128{ _v }
{
	
}

Vec4Impl::Vec4Impl(const Vec4Impl& _other) :m128{ _other.m128 }
{

}
Vec4Impl::Vec4Impl(Vec4Impl&& _other)noexcept : m128{ std::move(_other.m128) }
{

}

void Vec4Impl::copy(const Vec4Impl& _other)
{

	m128 = _other.m128;
}

void Vec4Impl::move(Vec4Impl&& _other)noexcept
{
	m128 = std::move(_other.m128);
}

CANDY_CORE_NAMESPACE_END
