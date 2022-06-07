/*****************************************************************//**
 * \file   ThreadHandle.cpp
 * \brief  �X���b�h�n���h��
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadHandle.h"

CANDY_NAMESPACE_BEGIN

// ����
void ThreadHandle::Close()
{
	ThreadHandleImpl::Close();
}

// ��r�֐��Q
bool ThreadHandle::operator==(const ThreadHandle& _other)const
{
	return ThreadHandleImpl::operator==(_other);
}
bool ThreadHandle::operator!=(const ThreadHandle& _other)const
{
	return ThreadHandleImpl::operator!=(_other);
}

CANDY_NAMESPACE_END
