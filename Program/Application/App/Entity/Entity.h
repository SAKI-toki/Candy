/*****************************************************************//**
 * \file   Entity.h
 * \brief  エンティティ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_ENTITY_H
#define CANDY_ENTITY_H

#include <App/AppInclude.h>

#include "EntityHandle.h"
#include <App/Component/System/List/ComponentList.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Transform;
}

class Entity
{
public:
	Entity() = default;
	~Entity() = default;
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&)noexcept = delete;
	Entity& operator=(Entity&&)noexcept = delete;

	// 初期化
	void startup();
	// 破棄
	void cleanup();

	const EntityHandle& getHandle()const { return m_Handle; }
	void setHandle(const EntityHandle& _handle) { m_Handle = _handle; }
	
	const std::string& getName()const { return m_Name; }
	void setName(std::string_view _name) { m_Name = _name; }

	// コンポーネントの追加
	template<typename T, typename ...ArgsT, Component::is_base_component_interface_t<T> = nullptr>
	void addComponent(ArgsT&& ..._args) { m_ComponentList.addComponent<T>(std::forward<ArgsT>(_args)...); }
	// コンポーネントの削除
	template<typename T, Component::is_base_component_interface_t<T> = nullptr>
	void removeComponent() { m_ComponentList.removeComponent<T>(); }
	// コンポーネントの取得
	template<typename T, Component::is_base_component_interface_t<T> = nullptr>
	T* getComponent() { return m_ComponentList.getComponent<T>(); }
	// コンポーネントの取得
	template<typename T, Component::is_base_component_interface_t<T> = nullptr>
	const T* getComponent()const { return m_ComponentList.getComponent<T>(); }

	// Transformコンポーネントの取得
	Component::Transform* getTransformComponent();
	const Component::Transform* getTransformComponent()const;

	bool isAlive()const { return m_IsAlive; }
	void setAlive(const bool _alive) { m_IsAlive = _alive; }

private:
	EntityHandle m_Handle{};
	std::string m_Name{};
	bool m_IsAlive = true;

	Component::List m_ComponentList;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_H
