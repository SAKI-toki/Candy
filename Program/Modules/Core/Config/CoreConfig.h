/*****************************************************************//**
 * \file   CoreConfig.h
 * \brief  コンフィグ
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_CONFIG_H
#define CANDY_CORE_CONFIG_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Config
{
	// アプリケーション名
	std::string GetAppName();

	// 1フレーム当たりの最大のアプリケーション時間
	f32 GetMaxAppTime();

	// 基準パス
	std::string GetBasePath();

	// データパス
	std::string GetDataPath();
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_CONFIG_H
