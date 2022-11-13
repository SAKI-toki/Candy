/*****************************************************************//**
 * \file   Sprite.h
 * \brief  Sprite
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_SPRITE_H
#define CANDY_APP_SPRITE_H

#include <App/AppInclude.h>
#include "SpriteImpl.h"

CANDY_APP_NAMESPACE_BEGIN

class Sprite
{
public:
	void startup();
	void cleanup();

	void render(const Mtx& _worldMtx, const Mtx& _rotMtx, const Color& _col);

	void setTexture(const std::string_view _path);
	void setTexture(const u32 _hash);

	void setDrawPriority(const s32 _priority) { if (m_Impl)m_Impl->setDrawPriority(_priority); }
	s32 getDrawPriority()const { return m_Impl ? m_Impl->getDrawPriority() : 0; }

private:
	std::shared_ptr<SpriteImpl> m_Impl;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_SPRITE_H
