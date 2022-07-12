/*****************************************************************//**
 * \file   CoreConfig.cpp
 * \brief  コンフィグ
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CoreConfig.h"

#include <CoreProxy/Config/CoreProxyConfig.h>

CANDY_CORE_NAMESPACE_BEGIN

// アプリケーション名
std::string Config::GetAppName()
{
	return coreProxy::Config::GetAppNameProxy();
}

// 1フレーム当たりの最大のアプリケーション時間
f32 Config::GetMaxAppTime()
{
	return coreProxy::Config::GetMaxAppTimeProxy();
}

// 基準パス
std::string Config::GetBasePath()
{
	return coreProxy::Config::GetBasePathProxy();
}

// データパス
std::string Config::GetDataPath()
{
	return coreProxy::Config::GetDataPathProxy();
}

CANDY_CORE_NAMESPACE_END
