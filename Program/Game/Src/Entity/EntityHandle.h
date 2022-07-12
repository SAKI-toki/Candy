#ifndef CANDY_ENTITY_HANDLE_H
#define CANDY_ENTITY_HANDLE_H

#include <GameInclude.h>

class Entity;
class EntityHandle : public core::Handle<Entity, EntityHandle>
{
public:
	Entity* getPtr()const;
};

inline constexpr EntityHandle INVALID_ENTITY_HANDLE = EntityHandle{};

#endif // CANDY_ENTITY_HANDLE_H
