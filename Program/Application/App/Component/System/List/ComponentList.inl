﻿/*****************************************************************//**
 * \file   ComponentManager.inl
 * \brief  コンポーネントリスト
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_LIST_INL
#define CANDY_APP_COMPONENT_LIST_INL

#include "ComponentList.h"
#include <App/Component/System/Manager/ComponentManager.h>
#include <App/Component/System/Table/ComponentRequireTable.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	// コンポーネントの追加(同じコンポーネントの追加はできない)
	template<typename T, typename ...ArgsT, is_base_component_interface_t<T>>
	std::weak_ptr<T> List::addComponent(ArgsT&& ..._args)
	{
		if (!getComponent<T>().expired())
		{
			return std::weak_ptr<T>{};
		}
		auto p = Component::Manager::template addComponent<T>(m_OwnerEntity, std::forward<ArgsT>(_args)...);
		auto sharedComponent = p.lock();
		if (!sharedComponent)
		{
			return std::weak_ptr<T>{};
		}
		addComponentInternal(p);
		std::vector<std::shared_ptr<Base>> requireComponents;
		RequireTable::RequireFuncListType requireFuncList;
		RequireTable::GetRequireFuncListFromType<T>(requireFuncList);
		for (const auto& requireFunc : requireFuncList)
		{
			auto requireComponent = requireFunc(*this).lock();
			if (!requireComponent)continue;
			requireComponents.push_back(requireComponent);
		}
		sharedComponent->startup();
		for (auto requireComponent : requireComponents)requireComponent->startup();
		return std::static_pointer_cast<T>(sharedComponent);
	}

	// コンポーネントの追加(RequireTable以外からの呼び出し禁止)
	template<typename T, typename ...ArgsT, is_base_component_interface_t<T>>
	std::weak_ptr<T> List::addComponentFromRequire(ArgsT&& ..._args)
	{
		if (!getComponent<T>().expired())
		{
			return std::weak_ptr<T>{};
		}
		auto p = Component::Manager::template addComponent<T>(m_OwnerEntity, std::forward<ArgsT>(_args)...);
		auto sharedComponent = p.lock();
		if (!sharedComponent)
		{
			return std::weak_ptr<T>{};
		}
		addComponentInternal(p);
		// startupはここではしない
		return std::static_pointer_cast<T>(sharedComponent);
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
	std::weak_ptr<T> List::getComponent()
	{
		for (auto& component : m_Components)
		{
			auto castComponent = T::Cast(component);
			if (!castComponent)continue;
			return castComponent;
		}
		return std::weak_ptr<T>{};
	}

	// コンポーネントの取得
	template<typename T, is_base_component_interface_t<T>>
	const std::weak_ptr<T> List::getComponent()const
	{
		for (auto& component : m_Components)
		{
			auto castComponent = T::Cast(component);
			if (!castComponent)continue;
			return castComponent;
		}
		return std::weak_ptr<T>{};
	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_LIST_INL