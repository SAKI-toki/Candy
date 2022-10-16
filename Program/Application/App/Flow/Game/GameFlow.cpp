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
	Mtx m1, m2;
	MtxSet(m1,
		{ 0, 1, 2, 3 },
		{ 8, 4, 5, 2 },
		{ 6, 3, 2, 3 },
		{ 2, 5, 8, 1 });
	MtxSet(m2,
		{ 9, 4, 6, 6 },
		{ 2, 3, 7, 2 },
		{ 8, 2, 1, 1 },
		{ 8, 2, 0, 0 });
	Mtx result;
	MtxMul(result, m1, m2);
	CANDY_LOG("{},{},{},{}", result.vec4[0].x, result.vec4[0].y, result.vec4[0].z, result.vec4[0].w);
	CANDY_LOG("{},{},{},{}", result.vec4[1].x, result.vec4[1].y, result.vec4[1].z, result.vec4[1].w);
	CANDY_LOG("{},{},{},{}", result.vec4[2].x, result.vec4[2].y, result.vec4[2].z, result.vec4[2].w);
	CANDY_LOG("{},{},{},{}", result.vec4[3].x, result.vec4[3].y, result.vec4[3].z, result.vec4[3].w);

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
