/*****************************************************************//**
 * \file   utilityConvertPosition.h
 * \brief  位置変換
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_UTILITY_CONVERT_POSITION_H
#define CANDY_APP_UTILITY_CONVERT_POSITION_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Utility
{
	// -1～1の2D位置を0～画面サイズの2D位置に変換
	Vec4 ToScreenPosFrom2DPos(const Vec4 _pos);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_UTILITY_CONVERT_POSITION_H
