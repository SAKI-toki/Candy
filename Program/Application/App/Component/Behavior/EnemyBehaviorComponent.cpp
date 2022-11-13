/*****************************************************************//**
 * \file   EnemyComponent.cpp
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "EnemyBehaviorComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(EnemyBehaviorComponent, BehaviorComponentBase);

void EnemyBehaviorComponent::updateImpl()
{
	Super::updateImpl();

	auto ownerEntity = getOwnerEntity().lock();
	if (!ownerEntity)return;
	auto transform = ownerEntity->getTransformComponent().lock();
	if (!transform)return;

	/*auto enemyRot = transform->getRot();
	enemyRot.y += 0.03f;
	transform->setRot(enemyRot);*/

	auto enemyPos = transform->getPos();
	DebugDraw::String::Add(Vec4{ 100.0f, 120.0f + enemyPos.x, 0.0f }, "EnemyPos:{0:.5f},{1:.5f}", enemyPos.x, enemyPos.y);
}

CANDY_APP_NAMESPACE_END
