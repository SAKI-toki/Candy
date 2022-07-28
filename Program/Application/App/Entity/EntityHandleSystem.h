#ifndef CANDY_ENTITY_HANDLE_SYSTEM_H
#define CANDY_ENTITY_HANDLE_SYSTEM_H

#include <App/AppInclude.h>

#include "Entity.h"
#include "EntityHandle.h"

CANDY_APP_NAMESPACE_BEGIN

class EntityHandleSystem : public core::HandleSystem<Entity, EntityHandle>
{

};

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_HANDLE_SYSTEM_H
