/*****************************************************************//**
 * \file   EntityManager.cpp
 * \brief  エンティティ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "EntityManager.h"
#include "Entity.h"
#include "EntityHandleSystem.h"

CANDY_APP_NAMESPACE_BEGIN

namespace EntityManager
{
	std::list<Entity*> m_Entities;
	EntityHandleSystem m_EntityHandleSystem;
}

void EntityManager::Startup()
{
	m_EntityHandleSystem.startup();
}

void EntityManager::Cleanup()
{
	m_EntityHandleSystem.cleanup();
}

Entity* EntityManager::CreateEntity(std::string name)
{
	Entity* entity = new Entity();
	if (!entity)return nullptr;

	EntityHandle handle = m_EntityHandleSystem.createHandle(entity);
	if (handle == INVALID_ENTITY_HANDLE)
	{
		delete entity;
		return nullptr;
	}

	entity->setHandle(handle);
	entity->setName(name);
	m_Entities.push_back(entity);
	entity->startup();
	return entity;
}

void EntityManager::ReleaseEntity(Entity* entity)
{
	if (!entity)return;
	entity->cleanup();
	m_EntityHandleSystem.releaseHandle(entity->getHandle());
	auto itr = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (itr != m_Entities.end())
	{
		delete (*itr);
		m_Entities.erase(itr);
	}
}

Entity* EntityManager::GetEntityPtr(EntityHandle handle)
{
	return m_EntityHandleSystem.getPtr(handle);
}

CANDY_APP_NAMESPACE_END

