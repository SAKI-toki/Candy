/*****************************************************************//**
 * \file   ComponentManager.inl
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_MANAGER_INL
#define CANDY_APP_COMPONENT_MANAGER_INL

#include "ComponentManager.h"
#include <App/Component/System/Priority/ComponentPriority.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Manager
	{
		inline std::vector<std::vector<Base*>> m_ComponentLists;
	}

	template<typename T, typename ...ArgsT, is_base_component_interface_t<T>>
	Base* Manager::addComponent(const EntityHandle _ownerHandle, ArgsT&& ..._args)
	{
		auto component = new T{ std::forward<ArgsT>(_args)... };
		component->setOwnerEntityHandle(_ownerHandle);
		m_ComponentLists[Priority::template GetFromType<T>()].push_back(component);
		return component;
	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_MANAGER_INL
