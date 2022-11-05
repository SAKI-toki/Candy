﻿/*****************************************************************//**
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

}

// 初期化
void GameFlow::Startup()
{
	Mtx m;
	float fov = 60.0f;
	float aspect = 9.0f / 16.0f;
	MtxPerspective(m, fov, aspect, 1.0f, 10.0f);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", m._11, m._12, m._13, m._14);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", m._21, m._22, m._23, m._24);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", m._31, m._32, m._33, m._34);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", m._41, m._42, m._43, m._44);

	CANDY_LOG("");

	auto mm = DirectX::XMMatrixPerspectiveFovLH(fov, aspect, 1, 10);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", mm.r[0].m128_f32[0], mm.r[0].m128_f32[1], mm.r[0].m128_f32[2], mm.r[0].m128_f32[3]);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", mm.r[1].m128_f32[0], mm.r[1].m128_f32[1], mm.r[1].m128_f32[2], mm.r[1].m128_f32[3]);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", mm.r[2].m128_f32[0], mm.r[2].m128_f32[1], mm.r[2].m128_f32[2], mm.r[2].m128_f32[3]);
	CANDY_LOG("{:.3f}, {:.3f}, {:.3f}, {:.3f}", mm.r[3].m128_f32[0], mm.r[3].m128_f32[1], mm.r[3].m128_f32[2], mm.r[3].m128_f32[3]);

	auto player = EntityManager::CreateEntity("Player");
	if (auto lockPlayer = player.lock())
	{
		lockPlayer->addComponent<PlayerBehaviorComponent>();
		auto renderer = lockPlayer->addComponent<SpriteRendererComponent>();
		if (auto lockRenderer = renderer.lock())
		{
			lockRenderer->setDrawPriority(-1);
			lockRenderer->setColor(RedColor);
		}
	}

	auto enemy = EntityManager::CreateEntity("Enemy");
	if (auto lockEnemy = enemy.lock())
	{
		lockEnemy->addComponent<EnemyBehaviorComponent>();
		lockEnemy->addComponent<SpriteRendererComponent>();
		/*if (auto transform = enemy->getTransformComponent())
		{
			transform->setPos({ 200.0f, 200.0f, 0.0f });
			transform->setScale({ 70.0f, 30.0f, 0.0f });
		}*/
	}

	auto camera = EntityManager::CreateEntity("Camera");
	if (auto lockCamera = camera.lock())
	{
		if (auto camera2d = lockCamera->addComponent<Camera2dComponent>().lock())
		{
			camera2d->setWidth(16.0f);
			camera2d->setHeight(9.0f);
			camera2d->setNear(0.1f);
			camera2d->setFar(100.0f);

			camera2d->setViewPos(Vec4{ 0.0f, 0.0f, -10.0f });
			camera2d->setTargetPos(ZeroVector);
			camera2d->setUp(UpVector);
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

}

// 描画
void GameFlow::Draw()
{

}

CANDY_APP_NAMESPACE_END
