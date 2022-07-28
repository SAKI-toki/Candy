#ifndef CANDY_ENTITY_H
#define CANDY_ENTITY_H

#include <App/AppInclude.h>

#include "EntityHandle.h"

CANDY_APP_NAMESPACE_BEGIN

class Entity
{
	friend class EntitySystem;

public:
	Entity() = default;
	~Entity() = default;
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&)noexcept = delete;
	Entity& operator=(Entity&&)noexcept = delete;

	EntityHandle getHandle()const { return m_Handle; }
	std::string getName()const { return m_Name; }
	void setName(std::string name) { m_Name = name; }

private:
	EntityHandle m_Handle{};
	std::string m_Name{};
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_H
