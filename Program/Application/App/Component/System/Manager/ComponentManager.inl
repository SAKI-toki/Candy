/*****************************************************************//**
 * \file   ComponentManager.inl
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_MANAGER_INL
#define CANDY_APP_COMPONENT_MANAGER_INL

#include "ComponentManager.h"
#include <App/Component/System/Table/ComponentPriorityTable.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Manager
	{
		inline std::vector<std::vector<Base*>> m_UpdateComponentLists;
		inline std::vector<std::vector<Base*>> m_RenderComponentLists;
	}

	template<typename T, typename ...ArgsT, is_base_component_interface_t<T>>
	Base* Manager::addComponent(Entity* const _ownerEntity, ArgsT&& ..._args)
	{
		auto component = new T{ std::forward<ArgsT>(_args)... };
		component->setOwnerEntity(_ownerEntity);

		const s32 updatePriority = PriorityTable::template GetUpdatePriorityFromType<T>();
		if (core::InRangeSize(updatePriority, 0, m_UpdateComponentLists.size()))
		{
			m_UpdateComponentLists[updatePriority].push_back(component);
		}

		const s32 renderPriority = PriorityTable::template GetRenderPriorityFromType<T>();
		if (core::InRangeSize(renderPriority, 0, m_RenderComponentLists.size()))
		{
			m_RenderComponentLists[renderPriority].push_back(component);
		}

		return component;
	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_MANAGER_INL
