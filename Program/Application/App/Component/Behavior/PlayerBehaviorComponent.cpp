/*****************************************************************//**
 * \file   PlayerBehaviorComponent.cpp
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "PlayerBehaviorComponent.h"
#include <App/Model/Primitive/ModelPrimitive.h>
#include <App/Entity/EntityManager.h>
#include "EnemyBehaviorComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(PlayerBehavior, Base);

	void PlayerBehavior::updateImpl()
	{
		base_type::updateImpl();

		auto transform = getOwnerEntity()->getTransformComponent();
		if (!transform)return;

		if (core::Input::IsKeyOn('F'))
		{
			transform->setPos(core::Input::GetClientMousePos());
		}

		auto playerPos = transform->getPos();

		Rect playerRect;
		playerRect.setSize(playerPos.x, playerPos.y, 20.0f, 50.0f);
		
		Model::Primitive::AddRect2D(playerRect, core::GetColorRGB32(0xff, 0xff, 0xff));

		if (auto enemy = m_EnemyHandle.getPtr())
		{
			if (auto enemyTransformComponent = enemy->getTransformComponent())
			{
				auto enemyPos = enemyTransformComponent->getPos();

				Rect enemyRect;
				enemyRect.setSize(enemyPos.x, enemyPos.y, 20.0f, 50.0f);

				if (physics::Collision2D::QuadQuad::IntersectConvex(playerRect, enemyRect))
				{
					EntityManager::ReleaseEntity(m_EnemyHandle);
				}
			}
		}
	}
}

CANDY_APP_NAMESPACE_END
