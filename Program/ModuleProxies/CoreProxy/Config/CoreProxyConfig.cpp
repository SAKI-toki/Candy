/*****************************************************************//**
 * \file   CoreProxyConfig.cpp
 * \brief  Coreのコンフィグ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include "CoreProxyConfig.h"

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Config
{
#define CANDY_BASE_PATH R"(D:\Candy\)"
#define CANDY_DATA_PATH CANDY_BASE_PATH R"(\Data\Win\)"
}

// アプリケーション名のプロキシ
std::string Config::GetAppNameProxy()
{
	return "Candy";
}

// 1フレーム当たりの最大のアプリケーション時間のプロキシ
f32 Config::GetMaxAppTimeProxy()
{
	return 1.0f / 30.0f;
}

// 基準パスのプロキシ
std::string Config::GetBasePathProxy()
{
	return CANDY_BASE_PATH;
}

// データパスのプロキシ
std::string Config::GetDataPathProxy()
{
	return CANDY_DATA_PATH;
}

CANDY_CORE_PROXY_NAMESPACE_END
