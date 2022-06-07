/*****************************************************************//**
 * \file   CriticalSection.cpp
 * \brief  クリティカルセクション
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CriticalSection.h"

CANDY_NAMESPACE_BEGIN

// 初期化
void CriticalSection::startup()
{
	CriticalSectionImpl::startup();
}
// 破棄
void CriticalSection::cleanup()
{
	CriticalSectionImpl::cleanup();
}
// 開始
void CriticalSection::enter()
{
	CriticalSectionImpl::enter();
}
// 終了
void CriticalSection::leave()
{
	CriticalSectionImpl::leave();
}

CANDY_NAMESPACE_END
