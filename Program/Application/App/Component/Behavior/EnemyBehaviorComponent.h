/*****************************************************************//**
 * \file   EnemyBehaviorComponent.h
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_ENEMY_BEHAVIOR_COMPONENT_H
#define CANDY_APP_ENEMY_BEHAVIOR_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "BehaviorBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

class EnemyBehaviorComponent : public BehaviorComponentBase
{
	CANDY_COMPONENT_DECLARE(EnemyBehaviorComponent, BehaviorComponentBase);

protected:
	void updateImpl()override;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_ENEMY_BEHAVIOR_COMPONENT_H
