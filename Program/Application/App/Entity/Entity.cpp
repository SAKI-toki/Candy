/*****************************************************************//**
 * \file   Entity.h
 * \brief  エンティティ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Entity.h"
#include <App/Component/Transform/TransformComponent.h>

CANDY_APP_NAMESPACE_BEGIN

void Entity::startup()
{
	m_ComponentList.setOwnerEntity(this);
}

void Entity::cleanup()
{
	m_ComponentList.clear();
}

// Transformコンポーネントの取得
Component::Transform* Entity::getTransformComponent()
{
	return m_ComponentList.getComponent<Component::Transform>();
}

// Transformコンポーネントの取得
const Component::Transform* Entity::getTransformComponent()const
{
	return m_ComponentList.getComponent<Component::Transform>();
}

CANDY_APP_NAMESPACE_END
