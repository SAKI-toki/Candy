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

	void EnemyBehavior::updateImpl()
	{
		base_type::updateImpl();
	}
}

CANDY_APP_NAMESPACE_END
