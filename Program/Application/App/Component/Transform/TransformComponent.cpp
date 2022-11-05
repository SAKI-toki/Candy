/*****************************************************************//**
 * \file   TransformComponent.cpp
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "TransformComponent.h"

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(TransformComponent, ComponentBase);

void TransformComponent::updateMatrix()
{
	if (!std::exchange(m_IsUpdateMatrix, false))return;
}

CANDY_APP_NAMESPACE_END
