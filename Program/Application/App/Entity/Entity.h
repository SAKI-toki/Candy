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

class Entity
{
public:
	Entity() = default;
	~Entity() = default;
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&)noexcept = delete;
	Entity& operator=(Entity&&)noexcept = delete;

	void startup();
	void cleanup();

	EntityHandle getHandle()const { return m_Handle; }
	std::string getName()const { return m_Name; }
	void setHandle(const EntityHandle _handle) { m_Handle = _handle; }
	void setName(std::string_view name) { m_Name = name; }

	template<typename T>
	void addComponent() { m_ComponentList.addComponent<T>(); }
	template<typename T>
	T* getComponent() { return m_ComponentList.getComponent<T>(); }
	template<typename T>
	const T* getComponent()const { return m_ComponentList.getComponent<T>(); }

private:
	EntityHandle m_Handle{};
	std::string m_Name{};

	Component::List m_ComponentList;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_H
