/*****************************************************************//**
 * \file   CoreProxyEntryPoint.cpp
 * \brief  エントリーポイントのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include "CoreProxyEntryPoint.h"
#include <Graphic/Module/GraphicModule.h>
#include <Sound/Module/SoundModule.h>
#include <App/Module/AppModule.h>

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace EntryPoint
{

}

// 前初期化のプロキシ
void EntryPoint::PreStartupProxy()
{

}

// 後初期化のプロキシ
void EntryPoint::PostStartupProxy()
{
	core::ModuleManager::startup(std::make_unique<core::Module>());

	core::ModuleManager::addModule(std::make_unique<graphic::Module>());
	core::ModuleManager::addModule(std::make_unique<sound::Module>());
	core::ModuleManager::addModule(std::make_unique<app::Module>());

	core::ModuleManager::startupModule();
}

// 前破棄のプロキシ
void EntryPoint::PreCleanupProxy()
{
	core::ModuleManager::cleanupModule();

	core::ModuleManager::cleanup();
}

// 後破棄のプロキシ
void EntryPoint::PostCleanupProxy()
{

}

// メインループの更新のプロキシ
void EntryPoint::MainLoopProxy()
{
	core::ModuleManager::update();
	core::ModuleManager::flip();
}

// メインループの終了判定のプロキシ
bool EntryPoint::IsEndMainLoopProxy()
{
	return core::Hardware::IsClose();
}

CANDY_CORE_PROXY_NAMESPACE_END
