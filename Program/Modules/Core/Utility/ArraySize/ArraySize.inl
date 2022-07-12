/*****************************************************************//**
 * \file   ArraySize.inl
 * \brief  生配列のサイズ取得
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#include "ArraySize.h"

CANDY_CORE_NAMESPACE_BEGIN

// 生配列のサイズ取得
template<typename T, s32 N>
inline constexpr s32 GetArraySize(T(&)[N]) { return N; }

CANDY_CORE_NAMESPACE_END
