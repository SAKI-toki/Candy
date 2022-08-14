/*****************************************************************//**
 * \file   ArraySize.inl
 * \brief  生配列のサイズ取得
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_CORE_ARRAY_SIZE_INL
#define CANDY_CORE_ARRAY_SIZE_INL

#include "ArraySize.h"

CANDY_CORE_NAMESPACE_BEGIN

// 生配列のサイズ取得
template<typename T, s32 N>
inline constexpr s32 GetArraySize(T(&)[N]) { return N; }

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_ARRAY_SIZE_INL
