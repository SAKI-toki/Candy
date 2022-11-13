/*****************************************************************//**
 * \file   ModelRendererComponent.cpp
 * \brief  Spriteレンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ModelRendererComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(ModelRendererComponent, RendererComponentBase);

void ModelRendererComponent::startupImpl()
{
	m_Model.startup();
}

void ModelRendererComponent::cleanupImpl()
{
	m_Model.cleanup();
}

void ModelRendererComponent::renderImpl()
{
	auto transform = getTransformComponent().lock();
	if (!transform)return;

	Mtx scalingMtx, rotationMtx, translationMtx, worldMtx;
	MtxScaling(scalingMtx, transform->getScale());
	MtxRotationZXY(rotationMtx, transform->getRot());
	MtxTranslation(translationMtx, transform->getPos());
	Mtx scalingMulRotationMtx;
	MtxMul(scalingMulRotationMtx, scalingMtx, rotationMtx);
	MtxMul(worldMtx, scalingMulRotationMtx, translationMtx);

	m_Model.render(worldMtx, rotationMtx);
}

CANDY_APP_NAMESPACE_END
