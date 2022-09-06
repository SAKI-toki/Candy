/*****************************************************************//**
 * \file   TransformComponent.cpp
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "TransformComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Transform, Base);

	void Transform::updateMatrix()
	{
		if (!std::exchange(m_IsUpdateMatrix, false))return;
	}
}

CANDY_APP_NAMESPACE_END
