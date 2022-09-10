/*****************************************************************//**
 * \file   Color.h
 * \brief  カラー定義
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_COLOR_H
#define CANDY_CORE_COLOR_H

#include <Core/CoreInclude.h>

#include <Core/Vec/Vec4.h>

CANDY_NAMESPACE_BEGIN

using Color = Vec4;

inline const Color WhiteColor		= Color{ 1.0f, 1.0f, 1.0f };
inline const Color BlackColor		= Color{ 0.0f, 0.0f, 0.0f };

inline const Color RedColor			= Color{ 1.0f, 0.0f, 0.0f };
inline const Color GreenColor		= Color{ 0.0f, 1.0f, 0.0f };
inline const Color BlueColor		= Color{ 0.0f, 0.0f, 1.0f };

inline const Color YellowColor		= Color{ 1.0f, 1.0f, 0.0f };
inline const Color PinkColor		= Color{ 1.0f, 0.0f, 1.0f };
inline const Color LightBlueColor	= Color{ 0.0f, 1.0f, 1.0f };

CANDY_NAMESPACE_END

#include "ConvColor.h"

#endif // CANDY_CORE_COLOR_H
