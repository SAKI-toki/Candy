/*****************************************************************//**
 * \file   PlatformImpl.h
 * \brief  プラットフォーム定義の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_PLATFORM_IMPL_H
#define CANDY_CORE_PLATFORM_IMPL_H

#include <Core/CoreInclude.h>

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <xaudio2.h>
#include <xaudio2fx.h>
#include <wrl/client.h>
#include <xmmintrin.h>

CANDY_CORE_NAMESPACE_BEGIN

#define CANDY_MAKE_FOURCC(x, y, z, w) (((w) << 24) | ((z) << 16) | ((y) << 8) | (x))
#define CANDY_MAKE_FOURCC_STR(str) (((str)[3] << 24) | ((str)[2] << 16) | ((str)[1] << 8) | (str)[0])

#define CANDY_MM_SHUFFLE(fp0, fp1, fp2, fp3) (((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | ((fp0)))

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_PLATFORM_IMPL_H
