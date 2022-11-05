/*****************************************************************//**
 * \file   Camera3dComponent.cpp
 * \brief  3Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Camera3dComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Camera3d, ComponentBase);

	void Camera3d::startupImpl()
	{
		Super::startupImpl();
	}

	void Camera3d::cleanupImpl()
	{
		Super::cleanupImpl();
	}

	void Camera3d::renderImpl()
	{
		Super::renderImpl();
	}

	void Camera3d::updateProjectionMtx()
	{
		MtxPerspective(m_ProjectionMtx, m_Fov, m_AspectRatio, m_Near, m_Far);
	}
}

CANDY_APP_NAMESPACE_END
