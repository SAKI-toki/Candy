/*****************************************************************//**
 * \file   ComponentPriority.cpp
 * \brief  コンポーネントの優先度
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentPriority.h"
#include <App/Component/Behavior/PlayerBehaviorComponent.h>
#include <App/Component/Behavior/EnemyBehaviorComponent.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Priority::Impl
	{
		const std::vector<std::vector<const void*>> PriorityTable =
		{
			// 0
			{
				PlayerBehavior::GetStaticClassId(),
			},
			// 1
			{
				EnemyBehavior::GetStaticClassId(),
			},
			// Last
			{
				nullptr,
			},
		};
	}

	s32 Priority::GetFromId(const void* const _id)
	{
		for (s32 i = 0; i < static_cast<s32>(Impl::PriorityTable.size()); ++i)
		{
			for (auto p : Impl::PriorityTable[i])
			{
				if (p != _id)continue;
				return i;
			}
		}

		CANDY_LOG_ERR("優先度が未設定のコンポーネントがあります");
		return static_cast<s32>(Impl::PriorityTable.size());
	}

	s32 Priority::GetCount()
	{
		// 未設定を最後に追加するため+1する
		return static_cast<s32>(Impl::PriorityTable.size()) + 1;
	}

}

CANDY_APP_NAMESPACE_END
