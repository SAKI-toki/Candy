/*****************************************************************//**
 * \file   EntityHandle.h
 * \brief  エンティティのハンドラ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_ENTITY_HANDLE_H
#define CANDY_ENTITY_HANDLE_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

class Entity;
class EntityHandle : public core::Handle<Entity, EntityHandle>
{
public:
	std::shared_ptr<Entity> getPtr()const;
};

inline constexpr EntityHandle INVALID_ENTITY_HANDLE = EntityHandle{};

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_HANDLE_H
