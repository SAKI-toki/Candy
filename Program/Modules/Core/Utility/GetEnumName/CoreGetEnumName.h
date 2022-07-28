/*****************************************************************//**
 * \file   CoreGetEnumName.h
 * \brief  enum名の取得
 * \author Yu Ishiyama.
 * \date   2022/07/24
 *********************************************************************/

#ifndef CANDY_CORE_GET_ENUM_NAME_H
#define CANDY_CORE_GET_ENUM_NAME_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

template<auto EnumV>
std::string GetEnumName();

CANDY_CORE_NAMESPACE_END

#include "CoreGetEnumName.inl"

#endif // CANDY_CORE_GET_ENUM_NAME_H
