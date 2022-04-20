#ifndef CANDY_FORCE_INCLUDE_H
#define CANDY_FORCE_INCLUDE_H

#define CANDY_NAMESPACE_NAME candy

#define CANDY_NAMESPACE_BEGIN namespace CANDY_NAMESPACE_NAME{
#define CANDY_NAMESPACE_END }

#include <utility>
#include <cstdint>
#include <memory>
#include <type_traits>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

inline void dummyFunc(...) {}

#include "BuildConfig/BuildConfig.h"
#include "Platform/Platform.h"

#if PLATFORM_WIN
#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl/client.h>
#include <xmmintrin.h>

template<typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

#endif // PLATFORM_WIN

#include <Type/ArithmetricType.h>
#include <Type/ClassDefine.h>
#include <Utility/UtilityDefine.h>
#include <Debug/Assert/Assert.h>
#include <Debug/Log/Log.h>
#include <Vec/Vec4.h>

using namespace candy;

#endif // CANDY_FORCE_INCLUDE_H
