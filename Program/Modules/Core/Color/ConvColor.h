/*****************************************************************//**
 * \file   ConvColor.h
 * \brief  カラー変換
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_CONV_COLOR_H
#define CANDY_CORE_CONV_COLOR_H

#include <Core/CoreInclude.h>

#include "Color.h"

CANDY_CORE_NAMESPACE_BEGIN

// 色の取得(RGBA32)
Color GetColorRGBA32(const u32 _r, const u32 _g, const u32 _b, const u32 _a);

// 色の取得(RGB32)
Color GetColorRGB32(const u32 _r, const u32 _g, const u32 _b);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CONV_COLOR_H
