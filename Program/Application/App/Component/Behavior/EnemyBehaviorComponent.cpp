/*****************************************************************//**
 * \file   EnemyComponent.cpp
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "EnemyBehaviorComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(EnemyBehavior, Base);

	void EnemyBehavior::startupImpl()
	{
		base_type::startupImpl();

		auto transform = getOwnerEntity()->getTransformComponent();
		if (!transform)return;

		transform->setPos(Vec4{ 100.0f, 100.0f, 0.0f });
	}

	void EnemyBehavior::updateImpl()
	{
		base_type::updateImpl();

		auto transform = getOwnerEntity()->getTransformComponent();
		if (!transform)return;

		auto pos = transform->getPos();

		Rect rect;
		rect.setSize(pos.x, pos.y, 20.0f, 50.0f);

		Model::Primitive::AddRect2D(rect, core::GetColorRGB32(0xff, 0x00, 0x00));
	}
}

CANDY_APP_NAMESPACE_END
