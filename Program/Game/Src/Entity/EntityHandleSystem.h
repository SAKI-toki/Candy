#ifndef CANDY_ENTITY_HANDLE_SYSTEM_H
#define CANDY_ENTITY_HANDLE_SYSTEM_H

#include <GameInclude.h>

#include "Entity.h"
#include "EntityHandle.h"

class EntityHandleSystem : public core::HandleSystem<Entity, EntityHandle>
{

};

#endif // CANDY_ENTITY_HANDLE_SYSTEM_H
