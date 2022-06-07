/*****************************************************************//**
 * \file   ConvColor.h
 * \brief  カラー変換
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CONV_COLOR_H
#define CANDY_CONV_COLOR_H

#include "Color.h"

CANDY_NAMESPACE_BEGIN

// 色の取得(RGBA32)
Vec4 GetColorRGBA32(const u32 _r, const u32 _g, const u32 _b, const u32 _a);

// 色の取得(RGB32)
Vec4 GetColorRGB32(const u32 _r, const u32 _g, const u32 _b);

CANDY_NAMESPACE_END

#endif // CANDY_CONV_COLOR_H
