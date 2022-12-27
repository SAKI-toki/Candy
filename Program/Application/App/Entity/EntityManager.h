/*****************************************************************//**
 * \file   EntityManager.h
 * \brief  エンティティ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_ENTITY_MANGER_H
#define CANDY_ENTITY_MANGER_H

#include <App/AppInclude.h>
#include "Entity.h"

CANDY_APP_NAMESPACE_BEGIN

namespace EntityManager
{
	void Startup();
	void Cleanup();

	void Flip();

	std::weak_ptr<Entity> CreateEntity(const std::string_view _name);
	void ReleaseEntity(const std::weak_ptr<Entity>& _entity);

	std::weak_ptr<Entity> FindEntity(const std::string_view _name);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_ENTITY_MANGER_H
