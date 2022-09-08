/*****************************************************************//**
 * \file   SpriteRenderingManager.h
 * \brief  Spriteレンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_SPRITE_RENDERING_MANAGER_H
#define CANDY_APP_SPRITE_RENDERING_MANAGER_H

#include <App/AppInclude.h>
#include "SpriteImpl.h"

CANDY_APP_NAMESPACE_BEGIN

namespace SpriteRenderingManager
{
	void Startup();
	void Cleanup();

	void Draw();

	void Add(const std::shared_ptr<SpriteImpl>& _sprite);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_SPRITE_RENDERING_MANAGER_H
