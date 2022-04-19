﻿#ifndef CANDY_ENTITY_SYSTEM_H
#define CANDY_ENTITY_SYSTEM_H

#include <list>
#include <string>
#include "Entity.h"
#include "EntityHandleSystem.h"

CANDY_NAMESPACE_BEGIN

class Entity;

class EntitySystem
{
	std::list<Entity*> m_Entities;
	EntityHandleSystem m_EntityHandleSystem;
public:
	void startup();
	void cleanup();

	Entity* createEntity(std::string name);
	void releaseEntity(Entity* entity);

	Entity* getEntityPtr(EntityHandle handle)const;
};

extern EntitySystem g_EntitySystem;

CANDY_NAMESPACE_END

#endif // CANDY_ENTITY_SYSTEM_H
