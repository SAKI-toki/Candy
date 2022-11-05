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
	auto ownerEntity = getOwnerEntity().lock();
	if (!ownerEntity)return;

	auto transform = ownerEntity->getTransformComponent().lock();
	if (!transform)return;

	auto pos = transform->getPos();

	m_Sprite.render(pos, getColor());
}

CANDY_APP_NAMESPACE_END
