#include "CriticalSectionImpl.h"

CANDY_NAMESPACE_BEGIN

void CriticalSectionImpl::startup()
{
	InitializeCriticalSection(&m_CriticalSection);
}
void CriticalSectionImpl::cleanup()
{
	DeleteCriticalSection(&m_CriticalSection);
}
void CriticalSectionImpl::enter()
{
	EnterCriticalSection(&m_CriticalSection);
}
void CriticalSectionImpl::leave()
{
	LeaveCriticalSection(&m_CriticalSection);
}

CANDY_NAMESPACE_END
