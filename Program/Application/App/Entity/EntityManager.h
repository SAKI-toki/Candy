/*****************************************************************//**
 * \file   EntityManager.h
 * \brief  エンティティ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_ENTITY_MANGER_H
#define CANDY_ENTITY_MANGER_H

#include <App/AppInclude.h>

#include "EntityHandle.h"

CANDY_APP_NAMESPACE_BEGIN

namespace EntityManager
{
	void Startup();
	void Cleanup();

	Entity* CreateEntity(std::string name);
	void ReleaseEntity(Entity* entity);

	Entity* GetEntityPtr(EntityHandle handle);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_MANGER_H
