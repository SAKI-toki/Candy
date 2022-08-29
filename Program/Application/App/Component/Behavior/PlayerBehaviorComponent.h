/*****************************************************************//**
 * \file   PlayerBehaviorComponent.h
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
#define CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H

#include <App/AppInclude.h>
#include <App/Component/ComponentBase.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class PlayerBehavior : public Base
	{
		CANDY_COMPONENT_DECLARE(PlayerBehavior, Base);

	public:
		void update()override;

		f32 value{};
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_PLAYER_BEHAVIOR_COMPONENT_H
