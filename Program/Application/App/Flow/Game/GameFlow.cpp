/*****************************************************************//**
 * \file   GameFlow.cpp
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "GameFlow.h"
#include <App/Flow/Scene/SceneFlow.h>
#include <App/Model/ModelManager.h>
#include <App/Debug/Draw/DebugDraw.h>
#include <App/Entity/EntityManager.h>
#include <App/Component/System/AllComponentInclude.h>
#include <App/Rendering/RenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

namespace GameFlow
{
	std::weak_ptr<Camera3dComponent> m_Camera3dComponent;
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
		/*auto renderer = lockPlayer->addComponent<SpriteRendererComponent>();
		if (auto lockRenderer = renderer.lock())
		{
			lockRenderer->setDrawPriority(-1);
			lockRenderer->setColor(RedColor);
		}*/
	}

	for (s32 i = 0; i < 30; ++i)
	{
		auto enemy = EntityManager::CreateEntity("Enemy");
		if (auto lockEnemy = enemy.lock())
		{
			lockEnemy->addComponent<EnemyBehaviorComponent>();
			lockEnemy->addComponent<ModelRendererComponent>();
			if (auto transform = lockEnemy->getTransformComponent().lock())
			{
				transform->setPos({ i * 10.0f, 0.0f, 0.0f });
			}
		}
	}

	auto camera = EntityManager::CreateEntity("Camera");
	if (auto lockCamera = camera.lock())
	{
		m_Camera3dComponent = lockCamera->addComponent<Camera3dComponent>();
		if (auto camera3d = m_Camera3dComponent.lock())
		{
			//camera3d->setWidth(16.0f);
			//camera3d->setHeight(9.0f);
			camera3d->setFov(1.0f);
			camera3d->setAspectRatio(16.0f / 9.0f);
			camera3d->setNear(0.1f);
			camera3d->setFar(10000.0f);

			camera3d->setViewPos(Vec4{ 50.0f, 10.0f, -150.0f });
			camera3d->setTargetPos(Vec4{ 50.0f, 10.0f, 0.0f });
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
	if (auto camera3d = m_Camera3dComponent.lock())
	{
		auto targetPos = camera3d->getTargetPos();
		targetPos.x = core::Loop(targetPos.x + 1.0f, 0.0f, 100.0f);
		camera3d->setTargetPos(targetPos);
	}
}

// 描画
void GameFlow::Draw()
{

}

CANDY_APP_NAMESPACE_END
