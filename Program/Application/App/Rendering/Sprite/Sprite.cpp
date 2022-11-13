/*****************************************************************//**
 * \file   Sprite.cpp
 * \brief  Sprite
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "Sprite.h"
#include "SpriteRenderingManager.h"

CANDY_APP_NAMESPACE_BEGIN

void Sprite::startup()
{
	m_Impl = std::make_shared<SpriteImpl>();
}

void Sprite::cleanup()
{
	m_Impl.reset();
}

void Sprite::render(const Mtx& _worldMtx, const Mtx& _rotMtx, const Color& _col)
{
	if (!m_Impl)return;

	m_Impl->render(_worldMtx, _rotMtx, _col);
	SpriteRenderingManager::AddSprite(m_Impl);
}

void Sprite::setTexture(const std::string_view _path)
{
	setTexture(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

void Sprite::setTexture(const u32 _hash)
{
	m_Impl->setTexture(_hash);
}

CANDY_APP_NAMESPACE_END
