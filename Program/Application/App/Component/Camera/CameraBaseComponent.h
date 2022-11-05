/*****************************************************************//**
 * \file   CameraBaseComponent.h
 * \brief  カメラコンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_CAMERA_BASE_COMPONENT_H
#define CANDY_APP_CAMERA_BASE_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class CameraBase : public ComponentBase
	{
		CANDY_COMPONENT_DECLARE(CameraBase, ComponentBase);

	public:
		void startupImpl()override;
		void cleanupImpl()override;

		void renderImpl()override;

		void setNear(const f32 _near) { m_Near = _near; }
		f32 getNear()const { return m_Near; }

		void setFar(const f32 _far) { m_Far = _far; }
		f32 getFar()const { return m_Far; }

		void setViewPos(const Vec4& _viewPos) { m_ViewPos = _viewPos; }
		Vec4 getViewPos()const { return m_ViewPos; }

		void setTargetPos(const Vec4& _targetPos) { m_TargetPos = _targetPos; }
		Vec4 getTargetPos()const { return m_TargetPos; }

		void setUp(const Vec4& _up) { m_Up = _up; }
		Vec4 getUp()const { return m_Up; }

		const Mtx& getViewMtx()const { return m_ViewMtx; }
		const Mtx& getProjectionMtx()const { return m_ProjectionMtx; }

	protected:
		virtual void updateViewMtx();
		virtual void updateProjectionMtx() = 0;

		f32 m_Near{};
		f32 m_Far{};

		Vec4 m_ViewPos;
		Vec4 m_TargetPos;
		Vec4 m_Up;

		Mtx m_ViewMtx;
		Mtx m_ProjectionMtx;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_CAMERA_BASE_COMPONENT_H
