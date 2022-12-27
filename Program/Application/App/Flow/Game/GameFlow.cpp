/*****************************************************************//**
 * \file   GameFlow.cpp
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "GameFlow.h"
#include <App/Flow/Scene/SceneFlow.h>
#include <App/Debug/Draw/DebugDraw.h>
#include <App/Entity/EntityManager.h>
#include <App/Component/System/AllComponentInclude.h>
#include <App/Rendering/RenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

namespace GameFlow
{

}

// 初期化
void GameFlow::Startup()
{
	const auto modelPath = core::Config::GetDataPath() + "Model/Test.bin";
	{
		const auto modelBufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
		if (core::FileSystem::RequestReadNoWait(modelPath, modelBufferInfo))
		{
			ModelResourceManager::Add(modelPath, modelBufferInfo);
		}
	}

	auto player = EntityManager::CreateEntity("Player");
	if (auto lockPlayer = player.lock())
	{
		lockPlayer->addComponent<PlayerBehaviorComponent>();
	}

	auto enemy = EntityManager::CreateEntity("Enemy");
	if (auto lockEnemy = enemy.lock())
	{
		lockEnemy->addComponent<EnemyBehaviorComponent>();
		if (auto modelRendererComponent = lockEnemy->addComponent<ModelRendererComponent>().lock())
		{
			modelRendererComponent->setModel(modelPath);
		}
		if (auto transform = lockEnemy->getTransformComponent().lock())
		{
			transform->setPos({ 0.0f, 0.0f, 0.0f });
		}
	}

	auto camera = EntityManager::CreateEntity("Camera");
	if (auto lockCamera = camera.lock())
	{
		if (auto camera3d = lockCamera->addComponent<Camera3dComponent>().lock())
		{
			camera3d->setFov(1.0f);
			camera3d->setAspectRatio(16.0f / 9.0f);
			camera3d->setNear(0.1f);
			camera3d->setFar(10000.0f);

			camera3d->setViewPos(Vec4{ 0.0f, 0.0f, -10.0f });
			camera3d->setTargetPos(Vec4{ 0.0f, 0.0f, 0.0f });
			camera3d->setUp(UpVector);
		}
	}
}

// 破棄
void GameFlow::Cleanup()
{

}

// 更新
void GameFlow::Update()
{
	if (auto entity = EntityManager::FindEntity("Enemy").lock())
	{
		if (auto transform = entity->getTransformComponent().lock())
		{
			auto rot = transform->getRot();
			//rot.x += 0.01f;
			rot.y += 0.02f;
			//rot.z += 0.03f;
			transform->setRot(rot);
		}
	}
}

// 描画
void GameFlow::Draw()
{

}

CANDY_APP_NAMESPACE_END
