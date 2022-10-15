/*****************************************************************//**
 * \file   MtxImpl.cpp
 * \brief  Matrixの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

MtxImpl::MtxImpl()
{

}

MtxImpl::MtxImpl(const MtxImpl& _other) :
	vector{ _other.vector[0], _other.vector[1], _other.vector[2], _other.vector[3] }
{

}

MtxImpl::MtxImpl(MtxImpl&& _other)noexcept :
	vector{ std::move(_other.vector[0]), std::move(_other.vector[1]), std::move(_other.vector[2]), std::move(_other.vector[3]) }
{

}

void MtxImpl::copy(const MtxImpl& _other)
{
	for (s32 i = 0; i < 4; ++i)vector[i] = _other.vector[i];
}

void MtxImpl::move(MtxImpl&& _other)noexcept
{
	for (s32 i = 0; i < 4; ++i)vector[i] = std::move(_other.vector[i]);
}

CANDY_CORE_NAMESPACE_END
