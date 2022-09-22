/*****************************************************************//**
 * \file   ComponentPriorityTable.h
 * \brief  コンポーネントの優先度テーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_PRORITY_TABLE_H
#define CANDY_APP_COMPONENT_PRORITY_TABLE_H

#include <App/AppInclude.h>
#include <App/Component/ComponentDef.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace PriorityTable
	{
		template<typename T, is_base_component_interface_t<T> = nullptr>
		s32 GetUpdatePriorityFromType();
		s32 GetUpdatePriorityFromId(const Component::ClassIdType _id);
		s32 GetUpdatePriorityCount();

		template<typename T, is_base_component_interface_t<T> = nullptr>
		s32 GetRenderPriorityFromType();
		s32 GetRenderPriorityFromId(const Component::ClassIdType _id);
		s32 GetRenderPriorityCount();
	}
}

CANDY_APP_NAMESPACE_END

#include "ComponentPriorityTable.inl"

#endif // CANDY_APP_COMPONENT_PRORITY_TABLE_H
