#include "EntitySystem.h"

void EntitySystem::startup()
{
	m_EntityHandleSystem.startup();
}
void EntitySystem::cleanup()
{
	m_EntityHandleSystem.cleanup();
}

Entity* EntitySystem::createEntity(std::string name)
{
	Entity* entity = new Entity();
	EntityHandle handle = m_EntityHandleSystem.createHandle(entity);
	if (handle == INVALID_ENTITY_HANDLE)
	{
		delete entity;
		return nullptr;
	}
	entity->m_Handle = handle;
	entity->m_Name = name;
	m_Entities.push_back(entity);
	return entity;
}

void EntitySystem::releaseEntity(Entity* entity)
{
	if (!entity)return;
	m_EntityHandleSystem.releaseHandle(entity->getHandle());
	auto itr = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (itr != m_Entities.end())
	{
		delete (*itr);
		m_Entities.erase(itr);
	}
}

Entity* EntitySystem::getEntityPtr(EntityHandle handle)const
{
	return m_EntityHandleSystem.getPtr(handle);
}

EntitySystem g_EntitySystem;
