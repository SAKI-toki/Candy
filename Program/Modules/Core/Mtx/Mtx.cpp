/*****************************************************************//**
 * \file   Mtx.cpp
 * \brief  Matrix
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Mtx.h"

CANDY_NAMESPACE_BEGIN

Mtx::Mtx()
{

}

Mtx::Mtx(const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4)
{
	*this = MtxSet(_v1, _v2, _v3, _v4);
}
Mtx::Mtx(const Mtx& _other) : core::MtxImpl{ _other }
{

}
Mtx& Mtx::operator=(const Mtx& _other)
{
	copy(_other);
	return *this;
}
Mtx::Mtx(Mtx&& _other)noexcept : core::MtxImpl{ std::move(_other) }
{

}
Mtx& Mtx::operator=(Mtx&& _other)noexcept
{
	move(std::move(_other));
	return *this;
}

Mtx Mtx::operator*(const Mtx& _other)const
{
	return MtxMul(*this, _other);
}

Mtx& Mtx::operator*=(const Mtx& _other)
{
	*this = *this * _other;
	return *this;
}

void Mtx::setIdentity()
{
	*this = MtxSetIdentity();
}

CANDY_NAMESPACE_END
