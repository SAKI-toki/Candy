/*****************************************************************//**
 * \file   Endian.h
 * \brief  インディアン
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_ENDIAN_H
#define CANDY_CORE_ENDIAN_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Endian
{
	// インディアン変換
	constexpr u16 Swap(const u16 _value);
	constexpr u32 Swap(const u32 _value);
	constexpr u64 Swap(const u64 _value);
}

CANDY_CORE_NAMESPACE_END

#include "Endian.inl"

#endif // CANDY_CORE_ENDIAN_H
