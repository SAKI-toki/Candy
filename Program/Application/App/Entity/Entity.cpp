/*****************************************************************//**
 * \file   Entity.h
 * \brief  エンティティ
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Entity.h"
#include <App/Component/Transform/TransformComponent.h>

CANDY_APP_NAMESPACE_BEGIN

void Entity::startup(const std::weak_ptr<Entity>& _entity)
{
	m_ComponentList.setOwnerEntity(_entity);
}

void Entity::cleanup()
{
	m_ComponentList.clear();
}

// Transformコンポーネントの取得
std::weak_ptr<TransformComponent> Entity::getTransformComponent()
{
	return m_ComponentList.getComponent<TransformComponent>();
}

// Transformコンポーネントの取得
const std::weak_ptr<TransformComponent> Entity::getTransformComponent()const
{
	return m_ComponentList.getComponent<TransformComponent>();
}

CANDY_APP_NAMESPACE_END
