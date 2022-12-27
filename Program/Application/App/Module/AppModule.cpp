/*****************************************************************//**
 * \file   AppModule.cpp
 * \brief  Appのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "AppModule.h"
#include <App/Rendering/RenderingManager.h>
#include <App/Rendering/Sprite/SpriteRenderingManager.h>
#include <App/Rendering/Model/ModelRenderingManager.h>
#include <App/Resource/Texture/TextureResourceManager.h>
#include <App/Resource/Model/ModelResourceManager.h>
#include <App/Flow/Game/GameFlow.h>
#include <App/Entity/EntityManager.h>
#include <App/Component/System/Manager/ComponentManager.h>
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
	TextureResourceManager::Startup();
	ModelResourceManager::Startup();
	RenderingManager::Startup();
	SpriteRenderingManager::Startup();
	ModelRenderingManager::Startup();
	Font::Startup();
	Debug::Startup();
	ComponentManager::Startup();
	EntityManager::Startup();
	GameFlow::Startup();
}

// 他モジュールに依存する破棄の実装部
void Module::cleanupImpl()
{
	GameFlow::Cleanup();
	EntityManager::Cleanup();
	ComponentManager::Cleanup();
	Debug::Cleanup();
	Font::Cleanup();
	ModelRenderingManager::Cleanup();
	SpriteRenderingManager::Cleanup();
	RenderingManager::Cleanup();
	ModelResourceManager::Cleanup();
	TextureResourceManager::Cleanup();
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
	ComponentManager::PreUpdate();
}

// 更新の実装部
void Module::updateImpl()
{
	ComponentManager::Update();
}

// 後更新の実装部
void Module::postUpdateImpl()
{
	ComponentManager::PostUpdate();
	Debug::Update();
}

// 前描画登録の実装部
void Module::preRenderImpl()
{
	ComponentManager::PreRender();
}

// 描画登録の実装部
void Module::renderImpl()
{
	ComponentManager::Render();
}

// 後描画登録の実装部
void Module::postRenderImpl()
{
	ComponentManager::PostRender();
}

// 前描画の実装部
void Module::preDrawImpl()
{
	RenderingManager::PreDraw();
}

// 描画の実装部
void Module::drawImpl()
{
	ModelRenderingManager::Draw();
	SpriteRenderingManager::Draw();
	Debug::Draw();
}

// 後描画の実装部
void Module::postDrawImpl()
{
	RenderingManager::PostDraw();
}

// フレーム終了の実装部
void Module::endFrameImpl()
{

}

// フリップの実装部
void Module::flipImpl()
{
	EntityManager::Flip();
}

CANDY_APP_NAMESPACE_END
