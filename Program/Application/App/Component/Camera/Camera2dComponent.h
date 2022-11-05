/*****************************************************************//**
 * \file   Camera2dComponent.h
 * \brief  2Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H
#define CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "CameraBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

class Camera2dComponent : public CameraComponentBase
{
	CANDY_COMPONENT_DECLARE(Camera2dComponent, CameraComponentBase);

public:
	void startupImpl()override;
	void cleanupImpl()override;

	void renderImpl()override;

	void updateProjectionMtx()override;

	void setHeight(const f32 _height) { m_Height = _height; }
	f32 getHeight()const { return m_Height; }

	void setWidth(const f32 _widht) { m_Width = _widht; }
	f32 getWidth()const { return m_Width; }

private:
	f32 m_Height{};
	f32 m_Width{};
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H
