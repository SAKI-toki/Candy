/*****************************************************************//**
 * \file   ComponentRequireTable.cpp
 * \brief  コンポーネントのRequireテーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentRequireTable.h"
#include <App/Component/System/AllComponentInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace RequireTable
	{
#define REQUIRE_COMPONENT_FUNC_DEFINE(CLASS_NAME, ...) [](List& _list){ return _list.addComponentFromRequire<CLASS_NAME>(__VA_ARGS__); }

		const std::vector<std::pair<Component::ClassIdType, RequireFuncListType>> RequireComponentTable = 
		{
			{
				ComponentBase::GetStaticClassId(),
				{
				}
			},
			{
				PlayerBehavior::GetStaticClassId(),
				{
					REQUIRE_COMPONENT_FUNC_DEFINE(Transform),
				}
			},
			{
				EnemyBehavior::GetStaticClassId(),
				{
					REQUIRE_COMPONENT_FUNC_DEFINE(Transform),
				}
			},
		};
		const RequireFuncListType NullRequireFuncList{};

#undef REQUIRE_COMPONENT_FUNC_DEFINE
	}

	const RequireTable::RequireFuncListType& RequireTable::GetRequireFuncListFromId(const Component::ClassIdType _id)
	{
		if (!_id)return NullRequireFuncList;

		for (const auto& requireComponentPair : RequireComponentTable)
		{
			if (requireComponentPair.first != _id)continue;
			return requireComponentPair.second;
		}
		return NullRequireFuncList;
	}
}

CANDY_APP_NAMESPACE_END
