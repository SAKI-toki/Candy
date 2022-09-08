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
	std::vector<EntityHandle> m_Entities;
}

// 初期化
void GameFlow::Startup()
{
	auto player = EntityManager::CreateEntity("Player");
	player->addComponent<Component::PlayerBehavior>();
	player->addComponent<Component::Renderer>();
	/*if (auto transform = player->getTransformComponent())
	{
		transform->setPos({ 100.0f, 100.0f, 0.0f });
		transform->setScale({ 20.0f, 40.0f, 0.0f });
	}*/
	m_Entities.push_back(player->getHandle());

	auto enemy = EntityManager::CreateEntity("Enemy");
	enemy->addComponent<Component::EnemyBehavior>();
	enemy->addComponent<Component::Renderer>();
	/*if (auto transform = enemy->getTransformComponent())
	{
		transform->setPos({ 200.0f, 200.0f, 0.0f });
		transform->setScale({ 70.0f, 30.0f, 0.0f });
	}*/
	m_Entities.push_back(enemy->getHandle());

	if (auto component = player->getComponent<Component::PlayerBehavior>())
	{
		component->setEnemyEntityHandle(enemy->getHandle());
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
