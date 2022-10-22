﻿/*****************************************************************//**
 * \file   ConvColor.cpp
 * \brief  カラー変換
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "ConvColor.h"

CANDY_CORE_NAMESPACE_BEGIN

// 色の取得(RGBA32)
Color GetColorRGBA32(const u32 _r, const u32 _g, const u32 _b, const u32 _a)
{
	return Color{
	static_cast<f32>(_r) / 255.0f,
	static_cast<f32>(_g) / 255.0f,
	static_cast<f32>(_b) / 255.0f,
	static_cast<f32>(_a) / 255.0f };
}

// 色の取得(RGB32)
Color GetColorRGB32(const u32 _r, const u32 _g, const u32 _b)
{
	return GetColorRGBA32(_r, _g, _b, 255);
}

CANDY_CORE_NAMESPACE_END

