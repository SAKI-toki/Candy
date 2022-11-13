/*****************************************************************//**
 * \file   SpriteRendererComponent.cpp
 * \brief  Spriteレンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "SpriteRendererComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(SpriteRendererComponent, RendererComponentBase);

void SpriteRendererComponent::startupImpl()
{
	m_Sprite.startup();
}

void SpriteRendererComponent::cleanupImpl()
{
	m_Sprite.cleanup();
}

void SpriteRendererComponent::renderImpl()
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

	m_Sprite.render(worldMtx, rotationMtx, getColor());
}

CANDY_APP_NAMESPACE_END
