/*****************************************************************//**
 * \file   CoreTypesImpl.h
 * \brief  型定義の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TYPES_IMPL_H
#define CANDY_CORE_TYPES_IMPL_H

#include <Core/CoreInclude.h>

CANDY_NAMESPACE_BEGIN

using WindowHandle = HWND;

template<typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

CANDY_NAMESPACE_END

#endif // CANDY_CORE_TYPES_IMPL_H
