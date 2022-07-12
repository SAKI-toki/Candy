/*****************************************************************//**
 * \file   CoreTypes.h
 * \brief  型定義
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TYPES_H
#define CANDY_CORE_TYPES_H

#include <Core/CoreInclude.h>

#include <cstdint>
#include <cfloat>

CANDY_NAMESPACE_BEGIN

using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using f32 = float;
using f64 = double;

using c8 = char8_t;
using c16 = char16_t;
using c32 = char32_t;

CANDY_NAMESPACE_END

#endif // CANDY_CORE_TYPES_H
