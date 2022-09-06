/*****************************************************************//**
 * \file   CoreSystemUpdateDrawIndex.h
 * \brief  更新と描画のインデックス
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "CoreSystemUpdateDrawIndex.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace UpdateDrawIndexSystem
{
	s32 m_UpdateIndex = 0;
	s32 m_DrawIndex = 1;
}

// フリップ
void UpdateDrawIndexSystem::Flip()
{
	std::swap(m_UpdateIndex, m_DrawIndex);
}

// 更新インデックス
s32 UpdateDrawIndexSystem::GetUpdateIndex()
{
	return m_UpdateIndex;
}

// 描画インデックス
s32 UpdateDrawIndexSystem::GetDrawIndex()
{
	return m_DrawIndex;
}

CANDY_CORE_NAMESPACE_END
