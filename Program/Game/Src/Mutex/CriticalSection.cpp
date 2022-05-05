#include "CriticalSection.h"

CANDY_NAMESPACE_BEGIN

void CriticalSection::startup()
{
	CriticalSectionImpl::startup();
}
void CriticalSection::cleanup()
{
	CriticalSectionImpl::cleanup();
}
void CriticalSection::enter()
{
	CriticalSectionImpl::enter();
}
void CriticalSection::leave()
{
	CriticalSectionImpl::leave();
}

CANDY_NAMESPACE_END
