/*****************************************************************//**
 * \file   Camera3dComponent.h
 * \brief  3Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_CAMERA_3D_RENDERER_COMPONENT_H
#define CANDY_APP_CAMERA_3D_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "CameraBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Camera3d : public CameraBase
	{
		CANDY_COMPONENT_DECLARE(Camera3d, CameraBase);

	public:
		void startupImpl()override;
		void cleanupImpl()override;

		void renderImpl()override;

		void updateProjectionMtx()override;

		void setFov(const f32 _fov) { m_Fov = _fov; }
		f32 getFov()const { return m_Fov; }

		void setAspectRatio(const f32 _aspectRatio) { m_AspectRatio = _aspectRatio; }
		f32 getAspectRatio()const { return m_AspectRatio; }

	private:
		f32 m_Fov{};
		f32 m_AspectRatio{};
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_CAMERA_3D_RENDERER_COMPONENT_H
