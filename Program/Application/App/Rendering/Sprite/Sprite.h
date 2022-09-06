/*****************************************************************//**
 * \file   Sprite.h
 * \brief  Sprite
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_SPRITE_H
#define CANDY_APP_SPRITE_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

class Sprite
{
public:
	void startup();
	void cleanup();

	void render();
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_SPRITE_H
