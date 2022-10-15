/*****************************************************************//**
 * \file   Mtx.h
 * \brief  Matrix
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MTX_H
#define CANDY_CORE_MTX_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Mtx/MtxImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

struct Mtx : core::MtxImpl
{
	using MtxImpl::MtxImpl;

	Mtx();
	Mtx(const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4);

	Mtx(const Mtx&);
	Mtx& operator=(const Mtx&);
	Mtx(Mtx&&)noexcept;
	Mtx& operator=(Mtx&&)noexcept;

	void setIdentity();
};

CANDY_NAMESPACE_END

#endif // CANDY_CORE_MTX_H
