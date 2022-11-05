/*****************************************************************//**
 * \file   Camera2dComponent.cpp
 * \brief  2Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "Camera2dComponent.h"
#include <App/Rendering/Sprite/SpriteRenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Camera2d, CameraBase);

	void Camera2d::startupImpl()
	{
		Super::startupImpl();
	}

	void Camera2d::cleanupImpl()
	{
		Super::cleanupImpl();
	}

	void Camera2d::renderImpl()
	{
		Super::renderImpl();

		SpriteRenderingManager::SetCamera(*this);
	}

	void Camera2d::updateProjectionMtx()
	{
		MtxOrthographic(m_ProjectionMtx, m_Width, m_Height, m_Near, m_Far);
	}
}

CANDY_APP_NAMESPACE_END
