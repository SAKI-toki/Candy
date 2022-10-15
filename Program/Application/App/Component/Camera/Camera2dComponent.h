/*****************************************************************//**
 * \file   Camera2DComponent.h
 * \brief  2Dカメラコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H
#define CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Camera2d : public Base
	{
		CANDY_COMPONENT_DECLARE(Camera2d, Base);

	public:
		void startupImpl()override;
		void cleanupImpl()override;

		void postUpdateImpl()override;

	private:
		Vec4 m_Pos{};
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_CAMERA_2D_RENDERER_COMPONENT_H
