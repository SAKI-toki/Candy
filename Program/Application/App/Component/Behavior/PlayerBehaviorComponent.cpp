/*****************************************************************//**
 * \file   PlayerBehaviorComponent.cpp
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "PlayerBehaviorComponent.h"
#include <App/Debug/Draw/DebugDraw.h>
#include <App/Entity/EntityManager.h>
#include "EnemyBehaviorComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(PlayerBehavior, Base);

	void PlayerBehavior::updateImpl()
	{
		base_type::updateImpl();

		auto ownerEntity = getOwnerEntity().lock();
		if (!ownerEntity)return;
		auto transform = ownerEntity->getTransformComponent().lock();
		if (!transform)return;

		if (core::Input::IsKeyOn('F'))
		{
			transform->setPos(core::Input::GetClientMousePos());
		}

		auto playerPos = transform->getPos();
		auto playerScale = transform->getScale();

		Rect playerRect;
		playerRect.setSize(playerPos.x, playerPos.y, playerScale.x, playerScale.y);

		if (auto enemy = m_EnemyEntity.lock())
		{
			if (auto enemyTransformComponent = enemy->getTransformComponent().lock())
			{
				auto enemyPos = enemyTransformComponent->getPos();
				auto enemyScale = enemyTransformComponent->getScale();

				Rect enemyRect;
				enemyRect.setSize(enemyPos.x, enemyPos.y, enemyScale.x, enemyScale.y);

				if (physics::Collision2D::QuadQuad::IntersectConvex(playerRect, enemyRect))
				{
					EntityManager::ReleaseEntity(m_EnemyEntity);
					m_EnemyEntity.reset();
				}
			}
		}
	}
}

CANDY_APP_NAMESPACE_END
