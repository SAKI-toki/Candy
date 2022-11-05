/*****************************************************************//**
 * \file   Camera3dComponent.cpp
 * \brief  3Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Camera3dComponent.h"

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(Camera3dComponent, CameraComponentBase);

void Camera3dComponent::startupImpl()
{
	Super::startupImpl();
}

void Camera3dComponent::cleanupImpl()
{
	Super::cleanupImpl();
}

void Camera3dComponent::renderImpl()
{
	Super::renderImpl();
}

void Camera3dComponent::updateProjectionMtx()
{
	MtxPerspective(m_ProjectionMtx, m_Fov, m_AspectRatio, m_Near, m_Far);
}

CANDY_APP_NAMESPACE_END
