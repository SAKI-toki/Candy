/*****************************************************************//**
 * \file   ComponentBase.inl
 * \brief  コンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_BASE_INL
#define CANDY_APP_COMPONENT_BASE_INL

#include <App/AppInclude.h>
#include "ComponentBase.h"
#include <App/Entity/Entity.h>

CANDY_APP_NAMESPACE_BEGIN

// コンポーネントの取得
template<typename T, IsBaseComponentComponentInterfaceT<T>>
std::weak_ptr<T> ComponentBase::getComponent()
{
	auto entity = m_OwnerEntity.lock();
	if (!entity)return std::weak_ptr<T>{};
	return entity->getComponent<T>();
}

// コンポーネントの取得
template<typename T, IsBaseComponentComponentInterfaceT<T>>
const std::weak_ptr<T> ComponentBase::getComponent()const
{
	auto entity = m_OwnerEntity.lock();
	if (!entity)return std::weak_ptr<T>{};
	return entity->getComponent<T>();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_BASE_INL
