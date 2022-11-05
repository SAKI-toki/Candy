/*****************************************************************//**
 * \file   SpriteRendererComponent.h
 * \brief  Spriteレンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_SPRITE_RENDERER_COMPONENT_H
#define CANDY_APP_SPRITE_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "RendererBaseComponent.h"
#include <App/Rendering/Sprite/Sprite.h>

CANDY_APP_NAMESPACE_BEGIN

class SpriteRendererComponent : public RendererComponentBase
{
	CANDY_COMPONENT_DECLARE(SpriteRendererComponent, RendererComponentBase);

public:
	void startupImpl()override;
	void cleanupImpl()override;
	void renderImpl()override;

	void setDrawPriority(const s32 _priority) { m_Sprite.setDrawPriority(_priority); }
	s32 getDrawPriority()const { return m_Sprite.getDrawPriority(); }

private:
	Sprite m_Sprite;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_SPRITE_RENDERER_COMPONENT_H
