#ifndef CANDY_ENTITY_HANDLE_SYSTEM_H
#define CANDY_ENTITY_HANDLE_SYSTEM_H

#include "Entity.h"
#include "EntityHandle.h"
#include <Handle/HandleSystem.h>

CANDY_NAMESPACE_BEGIN

class EntityHandleSystem : public HandleSystem<Entity, EntityHandle>
{

};

CANDY_NAMESPACE_END

#endif // CANDY_ENTITY_HANDLE_SYSTEM_H
