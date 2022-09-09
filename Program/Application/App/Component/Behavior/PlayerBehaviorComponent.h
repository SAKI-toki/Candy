/*****************************************************************//**
 * \file   PlayerBehaviorComponent.h
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
#define CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class PlayerBehavior : public Base
	{
		CANDY_COMPONENT_DECLARE(PlayerBehavior, Base);

	public:
		void updateImpl()override;

		void setEnemyEntity(const std::weak_ptr<Entity>& _entity) { m_EnemyEntity = _entity; }

		std::weak_ptr<Entity> m_EnemyEntity;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
