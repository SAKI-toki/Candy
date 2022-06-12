/*****************************************************************//**
 * \file   ThreadEventImpl.cpp
 * \brief  スレッドイベントの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/11
 *********************************************************************/

#include "ThreadEventImpl.h"

CANDY_NAMESPACE_BEGIN

 // 初期化
void ThreadEventImpl::startup()
{
	m_Handle = ::CreateEvent(nullptr, false, false, nullptr);
}
// 破棄
void ThreadEventImpl::cleanup()
{
	::CloseHandle(m_Handle);
}
// シグナル
void ThreadEventImpl::signal()
{
	::SetEvent(m_Handle);
}
// 待機
void ThreadEventImpl::wait()
{
	::WaitForSingleObjectEx(m_Handle, INFINITE, false);
}
// リセット
void ThreadEventImpl::reset()
{
	::ResetEvent(m_Handle);
}

CANDY_NAMESPACE_END
