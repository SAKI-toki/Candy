/*****************************************************************//**
 * \file   CriticalSectionImpl.cpp
 * \brief  クリティカルセクションの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CriticalSectionImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

// 初期化
void CriticalSectionImpl::startup()
{
	::InitializeCriticalSection(&m_CriticalSection);
}
// 破棄
void CriticalSectionImpl::cleanup()
{
	::DeleteCriticalSection(&m_CriticalSection);
}
// 開始
void CriticalSectionImpl::enter()
{
	::EnterCriticalSection(&m_CriticalSection);
}
// 終了
void CriticalSectionImpl::leave()
{
	::LeaveCriticalSection(&m_CriticalSection);
}

CANDY_CORE_NAMESPACE_END
