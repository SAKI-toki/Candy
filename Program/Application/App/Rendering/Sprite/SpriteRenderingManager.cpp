/*****************************************************************//**
 * \file   SpriteRenderingManager.cpp
 * \brief  Spriteレンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "SpriteRenderingManager.h"

CANDY_APP_NAMESPACE_BEGIN

namespace SpriteRenderingManager
{
	std::vector<std::shared_ptr<SpriteImpl>> m_DrawSpriteLists[2];
	core::CriticalSection m_CriticalSection;
}

void SpriteRenderingManager::Startup()
{
	m_CriticalSection.startup();
}

void SpriteRenderingManager::Cleanup()
{
	m_CriticalSection.cleanup();
}

void SpriteRenderingManager::Draw()
{
	auto& drawSpriteList = m_DrawSpriteLists[core::System::GetDrawIndex()];
	if (drawSpriteList.empty())return;

	auto& commandList = RenderingManager::GetSpriteCommandList();

	for (auto& drawSprite : drawSpriteList)
	{
		if (!drawSprite)continue;
		drawSprite->draw(commandList);
	}
	drawSpriteList.clear();
}

void SpriteRenderingManager::Add(const std::shared_ptr<SpriteImpl>& _sprite)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	auto& updateSpriteList = m_DrawSpriteLists[core::System::GetUpdateIndex()];
	updateSpriteList.push_back(_sprite);
}

CANDY_APP_NAMESPACE_END
