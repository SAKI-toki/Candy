/*****************************************************************//**
 * \file   EntityHandle.cpp
 * \brief  エンティティのハンドラ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/
#include "EntityHandle.h"
#include "EntityManager.h"

CANDY_APP_NAMESPACE_BEGIN

Entity* EntityHandle::getPtr()const
{
	return EntityManager::GetEntityPtr(*this);
}

CANDY_APP_NAMESPACE_END
