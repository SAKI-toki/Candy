#include "Time.h"

#if PLATFORM_WIN
#include "Platform/Win/TimeImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

void Time::Startup()
{
	Impl::Startup();
}
void Time::Cleanup()
{
	Impl::Cleanup();
}

Tick Time::GetTick()
{
	return Tick{};
}

CANDY_NAMESPACE_END
