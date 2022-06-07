/*****************************************************************//**
 * \file   ThreadHandle.cpp
 * \brief  スレッドハンドラ
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadHandle.h"

CANDY_NAMESPACE_BEGIN

// 閉じる
void ThreadHandle::Close()
{
	ThreadHandleImpl::Close();
}

// 比較関数群
bool ThreadHandle::operator==(const ThreadHandle& _other)const
{
	return ThreadHandleImpl::operator==(_other);
}
bool ThreadHandle::operator!=(const ThreadHandle& _other)const
{
	return ThreadHandleImpl::operator!=(_other);
}

CANDY_NAMESPACE_END
