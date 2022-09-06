/*****************************************************************//**
 * \file   CoreSystem.h
 * \brief  コアのシステム
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_SYSTEM_H
#define CANDY_CORE_SYSTEM_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace System
{
	// フリップ
	void Flip();

	// 更新インデックス
	s32 GetUpdateIndex();
	// 描画インデックス
	s32 GetDrawIndex();
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_SYSTEM_H
