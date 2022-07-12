#include "EntityHandle.h"
#include "EntitySystem.h"

Entity* EntityHandle::getPtr()const
{
	return g_EntitySystem.getEntityPtr(*this);
}
