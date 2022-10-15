/*****************************************************************//**
 * \file   Camera2dComponent.cpp
 * \brief  2Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Camera2dComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Camera2d, Base);

	void Camera2d::startupImpl()
	{
		base_type::startupImpl();
	}
	
	void Camera2d::cleanupImpl()
	{
		base_type::cleanupImpl();
	}

	void Camera2d::postUpdateImpl()
	{
		base_type::postUpdateImpl();
	}
}

CANDY_APP_NAMESPACE_END
