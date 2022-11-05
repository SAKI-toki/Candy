/*****************************************************************//**
 * \file   CameraBaseComponent.cpp
 * \brief  カメラコンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "CameraBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(CameraBase, ComponentBase);

	void CameraBase::startupImpl()
	{
		Super::startupImpl();
	}

	void CameraBase::cleanupImpl()
	{
		Super::cleanupImpl();
	}

	void CameraBase::renderImpl()
	{
		Super::renderImpl();

		updateViewMtx();
		updateProjectionMtx();
	}

	void CameraBase::updateViewMtx()
	{
		MtxLookAt(m_ViewMtx, m_ViewPos, m_TargetPos, m_Up);
	}
}

CANDY_APP_NAMESPACE_END
