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
	class Base;

	class List
	{
	public:
		List();
		~List();

		// クリア
		void clear();

		// コンポーネントの追加(同じコンポーネントの追加はできない)
		template<typename T, typename ...ArgsT, is_base_component_interface_t<T> = nullptr>
		T* addComponent(ArgsT&& ..._args);
		// コンポーネントの削除
		template<typename T, is_base_component_interface_t<T> = nullptr>
		void removeComponent();
		// コンポーネントの削除
		void removeComponent(const Base* const _component);
		// コンポーネントの取得
		template<typename T, is_base_component_interface_t<T> = nullptr>
		T* getComponent();
		// コンポーネントの取得
		template<typename T, is_base_component_interface_t<T> = nullptr>
		const T* getComponent()const;

		void setOwnerEntity(Entity* const _ownerEntity);

		// コンポーネントの追加(RequireTable以外からの呼び出し禁止)
		template<typename T, typename ...ArgsT, is_base_component_interface_t<T> = nullptr>
		T* addComponentFromRequire(ArgsT&& ..._args);

	private:
		// コンポーネントの追加
		void addComponentInternal(Base* const _component);
		// コンポーネントの削除
		void removeComponentInternal(const s32 _index);

		std::vector<Base*> m_Components;
		Entity* m_OwnerEntity = nullptr;
	};
}

CANDY_APP_NAMESPACE_END

#include "ComponentList.inl"

#endif // CANDY_APP_COMPONENT_LIST_H
