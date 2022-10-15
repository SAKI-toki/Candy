/*****************************************************************//**
 * \file   BehaviorBaseComponent.h
 * \brief  ビヘイビアのベースコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_BEHAVIOR_BASE_COMPONENT_H
#define CANDY_APP_BEHAVIOR_BASE_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class BehaviorBase : public Base
	{
		CANDY_COMPONENT_DECLARE(BehaviorBase, Base);
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_BEHAVIOR_BASE_COMPONENT_H
