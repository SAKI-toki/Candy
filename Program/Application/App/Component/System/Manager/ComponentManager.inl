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

namespace ComponentManager
{
	inline std::vector<std::shared_ptr<ComponentBase>> m_AllComponentLists;
	inline std::vector<std::vector<std::shared_ptr<ComponentBase>>> m_UpdateComponentLists;
	inline std::vector<std::vector<std::shared_ptr<ComponentBase>>> m_RenderComponentLists;
}

template<typename T, typename ...ArgsT, IsBaseComponentComponentInterfaceT<T>>
std::weak_ptr<ComponentBase> ComponentManager::addComponent(const std::weak_ptr<Entity>& _ownerEntity, ArgsT&& ..._args)
{
	auto component = std::make_shared<T>(std::forward<ArgsT>(_args)...);
	component->setOwnerEntity(_ownerEntity);
	m_AllComponentLists.push_back(component);

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

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_MANAGER_INL
