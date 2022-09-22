/*****************************************************************//**
 * \file   SpriteRendererComponent.cpp
 * \brief  Spriteレンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "SpriteRendererComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(SpriteRenderer, Base);

	void SpriteRenderer::startupImpl()
	{
		m_Sprite.startup();
	}

	void SpriteRenderer::cleanupImpl()
	{
		m_Sprite.cleanup();
	}

	void SpriteRenderer::renderImpl()
	{
		auto ownerEntity = getOwnerEntity().lock();
		if (!ownerEntity)return;

		auto transform = ownerEntity->getTransformComponent().lock();
		if (!transform)return;

		auto pos = transform->getPos();

		m_Sprite.render(pos, m_Color);
	}
}

CANDY_APP_NAMESPACE_END
