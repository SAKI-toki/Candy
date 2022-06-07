/*****************************************************************//**
 * \file   ThreadHandleImpl.cpp
 * \brief  �X���b�h�n���h���̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadHandleImpl.h"

CANDY_NAMESPACE_BEGIN

// ����
void ThreadHandleImpl::Close()
{
	::CloseHandle(m_Handle);
}

// �n���h���̃Z�b�g
void ThreadHandleImpl::setHandle(const HANDLE _handle)
{
	m_Handle = _handle;
}

// �n���h���̎擾
HANDLE ThreadHandleImpl::getHandle()const
{
	return m_Handle;
}

// ��r�֐��Q
bool ThreadHandleImpl::operator==(const ThreadHandleImpl& _other)const
{
	return m_Handle == _other.m_Handle;
}
bool ThreadHandleImpl::operator!=(const ThreadHandleImpl& _other)const
{
	return !(operator==(_other));
}

CANDY_NAMESPACE_END
