/*****************************************************************//**
 * \file   CoreSystem.h
 * \brief  コアのシステム
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "CoreSystem.h"
#include "CoreSystemUpdateDrawIndex.h"

CANDY_CORE_NAMESPACE_BEGIN

// フリップ
void System::Flip()
{
	UpdateDrawIndexSystem::Flip();
}

// 更新インデックス
s32 System::GetUpdateIndex()
{
	return UpdateDrawIndexSystem::GetUpdateIndex();
}

// 描画インデックス
s32 System::GetDrawIndex()
{
	return UpdateDrawIndexSystem::GetDrawIndex();
}

CANDY_CORE_NAMESPACE_END
