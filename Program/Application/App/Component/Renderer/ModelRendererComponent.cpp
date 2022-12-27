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

	Mtx rotationMtx;
	rotationMtx = MtxRotationZXY(transform->getRot());

	m_Model.render(MtxScaling(transform->getScale()) * rotationMtx * MtxTranslation(transform->getPos()), rotationMtx);
}

void ModelRendererComponent::setModel(const std::string_view _path)
{
	m_Model.setModel(_path);
}

CANDY_APP_NAMESPACE_END
