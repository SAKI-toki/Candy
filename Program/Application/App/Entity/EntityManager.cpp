/*****************************************************************//**
 * \file   EntityManager.cpp
 * \brief  エンティティ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "EntityManager.h"
#include "Entity.h"

CANDY_APP_NAMESPACE_BEGIN

namespace EntityManager
{
	std::list<Entity*> m_Entities;
	core::HandleSystem<Entity, EntityHandle> m_EntityHandleSystem;
}

void EntityManager::Startup()
{
	m_EntityHandleSystem.startup();
}

void EntityManager::Cleanup()
{
	m_EntityHandleSystem.cleanup();
}

Entity* EntityManager::CreateEntity(std::string_view _name)
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
	entity->setName(_name);
	m_Entities.push_back(entity);
	entity->startup();
	return entity;
}

void EntityManager::ReleaseEntity(const EntityHandle& _handle)
{
	auto entity = _handle.getPtr();
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

Entity* EntityManager::GetEntityPtr(const EntityHandle& _handle)
{
	return m_EntityHandleSystem.getPtr(_handle);
}

CANDY_APP_NAMESPACE_END

