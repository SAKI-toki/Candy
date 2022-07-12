/*****************************************************************//**
 * \file   GraphicInclude.h
 * \brief  Graphicのインクルードファイル
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_INCLUDE_H
#define CANDY_GRAPHIC_INCLUDE_H

#include "Core/Core.h"

#define CANDY_GRAPHIC_NAMESPACE_NAME graphic

#define CANDY_GRAPHIC_NAMESPACE_BEGIN CANDY_NAMESPACE_BEGIN namespace CANDY_GRAPHIC_NAMESPACE_NAME{
#define CANDY_GRAPHIC_NAMESPACE_END } CANDY_NAMESPACE_END

#include "Config/GraphicConfig.h"
#include "Types/GraphicTypes.h"

#if PLATFORM_WIN
#include "Platform/Win/Types/GraphicTypeConvert.h"
#endif // PLATFORM_WIN

#endif // CANDY_GRAPHIC_INCLUDE_H
