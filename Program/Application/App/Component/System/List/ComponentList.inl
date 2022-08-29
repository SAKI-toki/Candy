/*****************************************************************//**
 * \file   ComponentManager.inl
 * \brief  コンポーネントリスト
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_LIST_INL
#define CANDY_APP_COMPONENT_LIST_INL

#include "ComponentList.h"
#include <App/Component/System/Manager/ComponentManager.h>
#include <App/Component/System/Priority/ComponentPriority.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	// コンポーネントの追加(同じコンポーネントの追加はできない)
	template<typename T, typename ...ArgsT, is_base_component_interface_t<T>>
	T* List::addComponent(ArgsT&& ..._args)
	{
		if (getComponent<T>())return nullptr;
		auto p = Component::Manager::template addComponent<T>(m_OwnerEntityHandle, std::forward<ArgsT>(_args)...);
		addComponentInternal(p);
		return static_cast<T*>(p);
	}

	// コンポーネントの削除
	template<typename T, is_base_component_interface_t<T>>
	void List::removeComponent()
	{
		for (s32 i = 0; i < (s32)m_Components.size(); ++i)
		{
			auto castComponent = T::Cast(m_Components[i]);
			if (!castComponent)continue;
			removeComponentInternal(i);
			return;
		}
	}

	// コンポーネントの取得
	template<typename T, is_base_component_interface_t<T>>
	T* List::getComponent()
	{
		for (auto& component : m_Components)
		{
			auto castComponent = T::Cast(component);
			if (!castComponent)continue;
			return castComponent;
		}
		return nullptr;
	}

	// コンポーネントの取得
	template<typename T, is_base_component_interface_t<T>>
	const T* List::getComponent()const
	{
		for (auto& component : m_Components)
		{
			auto castComponent = T::Cast(component);
			if (!castComponent)continue;
			return castComponent;
		}
		return nullptr;
	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_LIST_INL
