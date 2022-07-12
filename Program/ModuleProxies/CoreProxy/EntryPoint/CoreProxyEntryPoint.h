/*****************************************************************//**
 * \file   CoreProxyEntryPoint.h
 * \brief  エントリーポイントのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include <CoreProxy/CoreProxyInclude.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace EntryPoint
{
	// 前初期化のプロキシ
	void PreStartupProxy();
	// 後初期化のプロキシ
	void PostStartupProxy();

	// 前破棄のプロキシ
	void PreCleanupProxy();
	// 後破棄のプロキシ
	void PostCleanupProxy();

	// メインループの更新のプロキシ
	void MainLoopProxy();

	// メインループの終了判定のプロキシ
	bool IsEndMainLoopProxy();
}

CANDY_CORE_PROXY_NAMESPACE_END
