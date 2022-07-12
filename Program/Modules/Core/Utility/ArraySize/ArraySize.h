/*****************************************************************//**
 * \file   ArraySize.h
 * \brief  生配列のサイズ取得
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_CORE_ARRAY_SIZE_H
#define CANDY_CORE_ARRAY_SIZE_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

// 生配列のサイズ取得
template<typename T, s32 N>
constexpr s32 GetArraySize(T(&)[N]);

CANDY_CORE_NAMESPACE_END

#include "ArraySize.inl"

#endif // CANDY_CORE_ARRAY_SIZE_H
