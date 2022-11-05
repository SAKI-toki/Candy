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

CANDY_COMPONENT_DEFINE(PlayerBehaviorComponent, BehaviorComponentBase);

void PlayerBehaviorComponent::updateImpl()
{
	Super::updateImpl();

	auto ownerEntity = getOwnerEntity().lock();
	if (!ownerEntity)return;
	auto transform = ownerEntity->getTransformComponent().lock();
	if (!transform)return;


	if (core::Input::IsKeyOn('D'))
	{
		transform->addPos(Vec4{ 0.1f * Global::GetAppTime() , 0.0f, 0.0f });
	}
	if (core::Input::IsKeyOn('A'))
	{
		transform->addPos(Vec4{ -0.1f * Global::GetAppTime() , 0.0f, 0.0f });
	}
	if (core::Input::IsKeyOn('W'))
	{
		transform->addPos(Vec4{ 0.0f, 0.1f * Global::GetAppTime(), 0.0f });
	}
	if (core::Input::IsKeyOn('S'))
	{
		transform->addPos(Vec4{ 0.0f, -0.1f * Global::GetAppTime(), 0.0f });
	}

	auto playerPos = transform->getPos();
	auto playerScale = transform->getScale();

	Rect playerRect;
	playerRect.setSize(playerPos.x, playerPos.y, playerScale.x, playerScale.y);
}

CANDY_APP_NAMESPACE_END
