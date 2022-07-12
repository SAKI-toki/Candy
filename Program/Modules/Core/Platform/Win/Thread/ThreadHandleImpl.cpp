/*****************************************************************//**
 * \file   ThreadHandleImpl.cpp
 * \brief  スレッドハンドラの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadHandleImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

// 閉じる
void ThreadHandleImpl::Close()
{
	::CloseHandle(m_Handle);
}

// ハンドラのセット
void ThreadHandleImpl::setHandle(const HANDLE _handle)
{
	m_Handle = _handle;
}

// ハンドラの取得
HANDLE ThreadHandleImpl::getHandle()const
{
	return m_Handle;
}

// 比較関数群
bool ThreadHandleImpl::operator==(const ThreadHandleImpl& _other)const
{
	return m_Handle == _other.m_Handle;
}
bool ThreadHandleImpl::operator!=(const ThreadHandleImpl& _other)const
{
	return !(operator==(_other));
}

CANDY_CORE_NAMESPACE_END
