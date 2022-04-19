#include "EntityHandle.h"
#include "EntitySystem.h"

CANDY_NAMESPACE_BEGIN

Entity* EntityHandle::getPtr()const
{
	return g_EntitySystem.getEntityPtr(*this);
}

CANDY_NAMESPACE_END
