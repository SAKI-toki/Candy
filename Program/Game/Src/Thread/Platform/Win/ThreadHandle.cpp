#include "ThreadHandle.h"

CANDY_NAMESPACE_BEGIN

void ThreadHandle::Close()
{
	::CloseHandle(m_Handle);
}

void ThreadHandle::setHandle(const HANDLE _handle)
{
	m_Handle = _handle;
}
HANDLE ThreadHandle::getHandle()const
{
	return m_Handle;
}

bool ThreadHandle::operator==(const ThreadHandle& _other)const
{
	return m_Handle == _other.m_Handle;
}
bool ThreadHandle::operator!=(const ThreadHandle& _other)const
{
	return !(operator==(_other));
}

CANDY_NAMESPACE_END
