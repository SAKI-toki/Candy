/*****************************************************************//**
 * \file   CoreProxyEntryPoint.cpp
 * \brief  エントリーポイントのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include "CoreProxyEntryPoint.h"
#include <Flow/Main/MainFlow.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

// 前初期化のプロキシ
void EntryPoint::PreStartupProxy()
{

}

// 後初期化のプロキシ
void EntryPoint::PostStartupProxy()
{
	MainFlow::Startup();
}

// 前破棄のプロキシ
void EntryPoint::PreCleanupProxy()
{
	MainFlow::Cleanup();
}

// 後破棄のプロキシ
void EntryPoint::PostCleanupProxy()
{

}

// メインループの更新のプロキシ
void EntryPoint::MainLoopProxy()
{
	MainFlow::Update();
}

// メインループの終了判定のプロキシ
bool EntryPoint::IsEndMainLoopProxy()
{
	return MainFlow::IsEnd();
}

CANDY_CORE_PROXY_NAMESPACE_END
