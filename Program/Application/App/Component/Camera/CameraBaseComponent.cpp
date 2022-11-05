/*****************************************************************//**
 * \file   CameraBaseComponent.cpp
 * \brief  カメラコンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "CameraBaseComponent.h"

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(CameraComponentBase, ComponentBase);

void CameraComponentBase::startupImpl()
{
	Super::startupImpl();
}

void CameraComponentBase::cleanupImpl()
{
	Super::cleanupImpl();
}

void CameraComponentBase::renderImpl()
{
	Super::renderImpl();

	updateViewMtx();
	updateProjectionMtx();
}

void CameraComponentBase::updateViewMtx()
{
	MtxLookAt(m_ViewMtx, m_ViewPos, m_TargetPos, m_Up);
}

CANDY_APP_NAMESPACE_END
