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
	std::list<std::shared_ptr<Entity>> m_Entities;
}

void EntityManager::Startup()
{

}

void EntityManager::Cleanup()
{
	while (!m_Entities.empty())
	{
		auto itr = m_Entities.begin();
		(*itr)->cleanup();
		m_Entities.erase(itr);
	}
}

void EntityManager::Flip()
{
	auto itr = m_Entities.begin();
	while (itr != m_Entities.end())
	{
		auto entity = *itr;
		if (entity->isAlive())
		{
			++itr;
			continue;
		}
		entity->cleanup();
		itr = m_Entities.erase(itr);
	}
}

std::weak_ptr<Entity> EntityManager::CreateEntity(const std::string_view _name)
{
	auto entity = std::make_shared<Entity>();
	if (!entity)return {};
	entity->setName(_name);
	m_Entities.push_back(entity);
	entity->startup(entity);
	return entity;
}

void EntityManager::ReleaseEntity(const std::weak_ptr<Entity>& _entity)
{
	auto lockEntity = _entity.lock();
	if (!lockEntity)return;
	if (!lockEntity->isAlive())return;
	lockEntity->setAlive(false);
}

std::weak_ptr<Entity> EntityManager::FindEntity(const std::string_view _name)
{
	for (const auto& entity : m_Entities)
	{
		if (!entity)continue;
		if (entity->getName() == _name)return entity;
	}
	return {};
}

CANDY_APP_NAMESPACE_END

