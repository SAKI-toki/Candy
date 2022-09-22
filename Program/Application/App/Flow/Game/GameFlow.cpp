/*****************************************************************//**
 * \file   GameFlow.cpp
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "GameFlow.h"
#include <App/Flow/Scene/SceneFlow.h>
#include <App/Model/Model.h>
#include <App/Debug/Draw/DebugDraw.h>
#include <App/Entity/EntityManager.h>
#include <App/Component/System/AllComponentInclude.h>
#include <App/Rendering/RenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

namespace GameFlow
{
	std::vector<std::weak_ptr<Entity>> m_Entities;
}

// 初期化
void GameFlow::Startup()
{
	auto player = EntityManager::CreateEntity("Player");
	m_Entities.push_back(player);
	auto lockPlayer = player.lock();
	if (lockPlayer)
	{
		lockPlayer->addComponent<Component::PlayerBehavior>();
		auto renderer = lockPlayer->addComponent<Component::SpriteRenderer>();
		if (auto lockRenderer = renderer.lock())
		{
			lockRenderer->setDrawPriority(-1);
			lockRenderer->setColor(RedColor);
		}
	}

	auto enemy = EntityManager::CreateEntity("Enemy");
	m_Entities.push_back(enemy);
	auto lockEnemy = enemy.lock();
	if (lockEnemy)
	{
		lockEnemy->addComponent<Component::EnemyBehavior>();
		lockEnemy->addComponent<Component::SpriteRenderer>();
		/*if (auto transform = enemy->getTransformComponent())
		{
			transform->setPos({ 200.0f, 200.0f, 0.0f });
			transform->setScale({ 70.0f, 30.0f, 0.0f });
		}*/
	}
}

// 破棄
void GameFlow::Cleanup()
{
	for (const auto& entity : m_Entities)EntityManager::ReleaseEntity(entity);
	m_Entities.clear();
}

// 更新
void GameFlow::Update()
{

}

// 描画
void GameFlow::Draw()
{

}

CANDY_APP_NAMESPACE_END
