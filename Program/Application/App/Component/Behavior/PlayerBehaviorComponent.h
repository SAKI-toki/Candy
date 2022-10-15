/*****************************************************************//**
 * \file   PlayerBehaviorComponent.h
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
#define CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "BehaviorBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class PlayerBehavior : public BehaviorBase
	{
		CANDY_COMPONENT_DECLARE(PlayerBehavior, BehaviorBase);

	public:
		void updateImpl()override;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
