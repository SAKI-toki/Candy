/*****************************************************************//**
 * \file   ComponentRequireTable.cpp
 * \brief  コンポーネントのRequireテーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentRequireTable.h"
#include <App/Component/System/AllComponentInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace RequireTable
{
#define REQUIRE_COMPONENT_FUNC_DEFINE(CLASS_NAME, ...) [](ComponentList& _list){ return _list.addComponentFromRequire<CLASS_NAME>(__VA_ARGS__); }

	const std::vector<std::pair<ComponentClassIdType, RequireFuncListType>> RequireComponentTable =
	{
		{
			ComponentBase::GetStaticClassId(),
			{
			}
		},
		{
			PlayerBehaviorComponent::GetStaticClassId(),
			{
				REQUIRE_COMPONENT_FUNC_DEFINE(TransformComponent),
			}
		},
		{
			EnemyBehaviorComponent::GetStaticClassId(),
			{
				REQUIRE_COMPONENT_FUNC_DEFINE(TransformComponent),
			}
		},
	};
	const RequireFuncListType NullRequireFuncList{};

#undef REQUIRE_COMPONENT_FUNC_DEFINE
}

const RequireTable::RequireFuncListType& RequireTable::GetRequireFuncListFromId(const ComponentClassIdType _id)
{
	if (!_id)return NullRequireFuncList;

	for (const auto& requireComponentPair : RequireComponentTable)
	{
		if (requireComponentPair.first != _id)continue;
		return requireComponentPair.second;
	}
	return NullRequireFuncList;
}

CANDY_APP_NAMESPACE_END
