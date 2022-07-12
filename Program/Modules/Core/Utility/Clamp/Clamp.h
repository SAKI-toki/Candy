/*****************************************************************//**
 * \file   Clamp.h
 * \brief  クランプ
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_CLAMP_H
#define CANDY_CORE_CLAMP_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

// 指定範囲にクランプ
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT Clamp(const T _v, const MinT _min, const MaxT _max);

// [0-1]にクランプ
template<typename T>
T Clamp01(const T _v);

CANDY_CORE_NAMESPACE_END

#include "Clamp.inl"

#endif // CANDY_CORE_CLAMP_H
