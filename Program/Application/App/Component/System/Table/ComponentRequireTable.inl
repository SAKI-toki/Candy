/*****************************************************************//**
 * \file   ComponentRequireTable.inl
 * \brief  コンポーネントのRequireテーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_REQUIRE_TABLE_INL
#define CANDY_APP_COMPONENT_REQUIRE_TABLE_INL

#include "ComponentRequireTable.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	template<typename T>
	void RequireTable::GetRequireFuncListFromType(RequireFuncListType& _result)
	{
		const auto& requireFuncList = GetRequireFuncListFromId(T::GetStaticClassId());
		_result.insert(_result.end(), requireFuncList.begin(), requireFuncList.end());
		GetRequireFuncListFromType<typename T::Super>(_result);
	}

	template<>
	inline void RequireTable::GetRequireFuncListFromType<ComponentInterface>(RequireFuncListType&)
	{

	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_REQUIRE_TABLE_INL
