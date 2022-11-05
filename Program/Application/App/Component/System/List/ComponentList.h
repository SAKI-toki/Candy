/*****************************************************************//**
 * \file   ComponentList.h
 * \brief  コンポーネントリスト
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_LIST_H
#define CANDY_APP_COMPONENT_LIST_H

#include <App/AppInclude.h>
#include <App/Component/ComponentDef.h>

CANDY_APP_NAMESPACE_BEGIN

class Entity;

namespace Component
{
	class ComponentBase;

	class List
	{
	public:
		List();
		~List();

		// クリア
		void clear();

		// コンポーネントの追加(同じコンポーネントの追加はできない)
		template<typename T, typename ...ArgsT, IsBaseComponentComponentInterfaceT<T> = nullptr>
		std::weak_ptr<T> addComponent(ArgsT&& ..._args);
		// コンポーネントの削除
		template<typename T, IsBaseComponentComponentInterfaceT<T> = nullptr>
		void removeComponent();
		// コンポーネントの削除
		void removeComponent(const std::weak_ptr<ComponentBase>& _component);
		// コンポーネントの取得
		template<typename T, IsBaseComponentComponentInterfaceT<T> = nullptr>
		std::weak_ptr<T> getComponent();
		// コンポーネントの取得
		template<typename T, IsBaseComponentComponentInterfaceT<T> = nullptr>
		const std::weak_ptr<T> getComponent()const;

		void setOwnerEntity(const std::weak_ptr<Entity>& _ownerEntity) { m_OwnerEntity = _ownerEntity; }

		// コンポーネントの追加(RequireTable以外からの呼び出し禁止)
		template<typename T, typename ...ArgsT, IsBaseComponentComponentInterfaceT<T> = nullptr>
		std::weak_ptr<T> addComponentFromRequire(ArgsT&& ..._args);

	private:
		// コンポーネントの追加
		void addComponentInternal(const std::weak_ptr<ComponentBase>& _component);
		// コンポーネントの削除
		void removeComponentInternal(const s32 _index);

		std::vector<std::weak_ptr<ComponentBase>> m_Components;
		std::weak_ptr<Entity> m_OwnerEntity;
	};
}

CANDY_APP_NAMESPACE_END

#include "ComponentList.inl"

#endif // CANDY_APP_COMPONENT_LIST_H
