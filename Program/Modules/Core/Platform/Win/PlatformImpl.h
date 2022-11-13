/*****************************************************************//**
 * \file   PlatformImpl.h
 * \brief  プラットフォーム定義の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_PLATFORM_IMPL_H
#define CANDY_CORE_PLATFORM_IMPL_H

#include <Core/CoreInclude.h>

#define NOMINMAX

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <xaudio2.h>
#include <xaudio2fx.h>
#include <wrl/client.h>
#include <xmmintrin.h>
#include <emmintrin.h>

CANDY_NAMESPACE_BEGIN

using vector_type = __m128;
using vectori_type = __m128i;

#define CANDY_MAKE_FOURCC(x, y, z, w) (((u32)(w) << 24) | ((u32)(z) << 16) | ((u32)(y) << 8) | (u32)(x))
#define CANDY_MAKE_FOURCC_STR(str) (((u32)(str)[3] << 24) | ((u32)(str)[2] << 16) | ((u32)(str)[1] << 8) | (u32)(str)[0])

#define CANDY_MM_SHUFFLE(fp0, fp1, fp2, fp3) (((u32)(fp3) << 6) | ((u32)(fp2) << 4) | ((u32)(fp1) << 2) | ((u32)(fp0)))

CANDY_NAMESPACE_END

#endif // CANDY_CORE_PLATFORM_IMPL_H
