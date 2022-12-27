/*****************************************************************//**
 * \file   Camera2dComponent.cpp
 * \brief  2Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Camera2dComponent.h"
#include <App/Rendering/Sprite/SpriteRenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(Camera2dComponent, CameraComponentBase);

void Camera2dComponent::startupImpl()
{
	Super::startupImpl();
}

void Camera2dComponent::cleanupImpl()
{
	Super::cleanupImpl();
}

void Camera2dComponent::renderImpl()
{
	Super::renderImpl();

	SpriteRenderingManager::SetCamera(*this);
}

void Camera2dComponent::updateProjectionMtx()
{
	m_ProjectionMtx = MtxOrthographic(m_Width, m_Height, m_Near, m_Far);
}

CANDY_APP_NAMESPACE_END
