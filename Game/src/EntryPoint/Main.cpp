#if PLATFORM_WIN
#include "Platform/Win/MainImpl.h"
#endif // PLATFORM_WIN

#include <Hardware/Hardware.h>
#include <Flow/Main/MainFlow.h>

ENTRY_POINT_MAIN()
{
	ENTRY_POINT_STARTUP();

	MainFlow::Startup();
	while (!MainFlow::IsEnd())
	{
		MainFlow::Update();
	}
	MainFlow::Cleanup();

	ENTRY_POINT_CLEANUP();

	RETURN_ENTRY_POINT();
}
