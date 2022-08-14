/*****************************************************************//**
 * \file   utilityConvertPosition.h
 * \brief  位置変換
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "UtilityConvertPosition.h"

CANDY_APP_NAMESPACE_BEGIN

// -1～1の2D位置を0～画面サイズの2D位置に変換
Vec4 Utility::ToScreenPosFrom2DPos(const Vec4 _pos)
{
	Vec4 v = ZeroVector;

	const auto screenWidth = graphic::Config::GetScreenWidth();
	const auto screenHeight = graphic::Config::GetScreenHeight();

	v.x = (_pos.x - screenWidth / 2.0f) / screenWidth * 2.0f;
	v.y = (_pos.y - screenHeight / 2.0f) / screenHeight * 2.0f * -1.0f;

	return v;
}

CANDY_APP_NAMESPACE_END
