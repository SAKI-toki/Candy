/*****************************************************************//**
 * \file   ComponentRequireTable.h
 * \brief  コンポーネントのRequireテーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_REQUIRE_TABLE_H
#define CANDY_APP_COMPONENT_REQUIRE_TABLE_H

#include <App/AppInclude.h>
#include <App/Component/ComponentDef.h>
#include <App/Component/System/List/ComponentList.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace RequireTable
	{
		using RequireFuncType = std::function<std::weak_ptr<Base> (List&)>;
		using RequireFuncListType = std::vector<RequireFuncType>;

		template<typename T>
		void GetRequireFuncListFromType(RequireFuncListType& _result);
		const RequireFuncListType& GetRequireFuncListFromId(const void* const _id);
	}
}

CANDY_APP_NAMESPACE_END

#include "ComponentRequireTable.inl"

#endif // CANDY_APP_COMPONENT_REQUIRE_TABLE_H
