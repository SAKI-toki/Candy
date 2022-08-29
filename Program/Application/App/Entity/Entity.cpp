/*****************************************************************//**
 * \file   Entity.h
 * \brief  エンティティ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Entity.h"

CANDY_APP_NAMESPACE_BEGIN

void Entity::startup()
{
	m_ComponentList.setOwnerEntityHandle(m_Handle);
}

void Entity::cleanup()
{
	m_ComponentList.clear();
}

CANDY_APP_NAMESPACE_END
