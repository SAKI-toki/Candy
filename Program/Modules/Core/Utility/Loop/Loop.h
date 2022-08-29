/*****************************************************************//**
 * \file   Loop.h
 * \brief  値のループ
 * \author Yu Ishiyama.
 * \date   2022/06/09
 *********************************************************************/

#ifndef CANDY_CORE_LOOP_H
#define CANDY_CORE_LOOP_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

// ループ
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT Loop(const T _v, const MinT _min, const MaxT _max);

// ループ(サイズ)
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT LoopSize(const T _v, const MinT _min, const MaxT _max);

// ループ(厳密)
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT LoopStrict(const T _v, const MinT _min, const MaxT _max);
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT LoopStrictInt(const T _v, const MinT _min, const MaxT _max);

// ループ(サイズ・厳密)
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT LoopSizeStrict(const T _v, const MinT _min, const MaxT _max);
template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT LoopSizeStrictInt(const T _v, const MinT _min, const MaxT _max);

CANDY_CORE_NAMESPACE_END

#include "Loop.inl"

#endif // CANDY_CORE_LOOP_H
