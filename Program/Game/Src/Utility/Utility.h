#ifndef CANDY_UTILITY_H
#define CANDY_UTILITY_H

#include "Clamp/Clamp.h"
#include "Loop/Loop.h"
#include "MinMax/MinMax.h"
#include "Hash/Hash.h"
#include "Path/Path.h"
#include "StringSystem/StringSystem.h"
#include "Endian/Endian.h"

CANDY_NAMESPACE_BEGIN

template<typename T, s32 N>
inline constexpr s32 GetArraySize(T(&)[N]) { return N; }

CANDY_NAMESPACE_END

#endif // CANDY_UTILITY_H