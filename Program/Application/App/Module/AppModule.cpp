/*****************************************************************//**
 * \file   AppModule.cpp
 * \brief  Appのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "AppModule.h"
#include <App/Flow/Game/GameFlow.h>
#include <App/Entity/EntityManager.h>
#include <App/Component/System/Manager/ComponentManager.h>
#include <App/Model/Model.h>
#include <App/Font/Font.h>
#include <App/Debug/Debug.h>

CANDY_APP_NAMESPACE_BEGIN

// 他モジュールに依存しない初期化の実装部
void Module::initializeImpl()
{
	Global::Startup();
}

// 他モジュールに依存する初期化の実装部
void Module::startupImpl()
{
	Model::Startup();
	Font::Startup();
	Debug::Startup();
	Component::Manager::Startup();
	EntityManager::Startup();
	GameFlow::Startup();
}

// 他モジュールに依存する破棄の実装部
void Module::cleanupImpl()
{
	GameFlow::Cleanup();
	EntityManager::Cleanup();
	Component::Manager::Cleanup();
	Debug::Cleanup();
	Font::Cleanup();
	Model::Cleanup();
}

// 他モジュールに依存しない破棄の実装部
void Module::releaseImpl()
{
	Global::Cleanup();
}

// フレーム開始の実装部
void Module::beginFrameImpl()
{
	Global::Update();
}

// 前更新の実装部
void Module::preUpdateImpl()
{
	GameFlow::Update();
	Component::Manager::PreUpdate();
}

// 更新の実装部
void Module::updateImpl()
{
	Component::Manager::Update();
}

// 後更新の実装部
void Module::postUpdateImpl()
{
	Component::Manager::PostUpdate();
	Debug::Update();
}

// 前描画の実装部
void Module::preDrawImpl()
{

}

// 描画の実装部
void Module::drawImpl()
{
	GameFlow::Draw();
	Model::Primitive::Draw(graphic::System::GetCommandList());
	Debug::Draw();
}

// 後描画の実装部
void Module::postDrawImpl()
{

}
// フレーム終了の実装部
void Module::endFrameImpl()
{

}

// フリップの実装部
void Module::flipImpl()
{
	Global::Flip();
}

CANDY_APP_NAMESPACE_END
