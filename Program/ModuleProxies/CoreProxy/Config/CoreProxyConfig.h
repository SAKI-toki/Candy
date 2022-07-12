/*****************************************************************//**
 * \file   CoreProxyConfig.h
 * \brief  Coreのコンフィグ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#ifndef CANDY_CORE_PROXY_CONFIG_H
#define CANDY_CORE_PROXY_CONFIG_H

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Config
{
	// アプリケーション名のプロキシ
	std::string GetAppNameProxy();

	// 1フレーム当たりの最大のアプリケーション時間のプロキシ
	f32 GetMaxAppTimeProxy();

	// 基準パスのプロキシ
	std::string GetBasePathProxy();

	// データパスのプロキシ
	std::string GetDataPathProxy();
}

CANDY_CORE_PROXY_NAMESPACE_END

#endif // CANDY_CORE_PROXY_CONFIG_H
