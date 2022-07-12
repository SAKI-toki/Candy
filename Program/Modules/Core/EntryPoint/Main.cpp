/*****************************************************************//**
 * \file   Main.cpp
 * \brief  エントリーポイント
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include <Core/CoreInclude.h>

#include <CoreProxy/EntryPoint/CoreProxyEntryPoint.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/EntryPoint/MainImpl.h>
#endif // PLATFORM_WIN

// エントリーポイント
ENTRY_POINT_MAIN()
{
	candy::coreProxy::EntryPoint::PreStartupProxy();

	ENTRY_POINT_STARTUP();

	candy::coreProxy::EntryPoint::PostStartupProxy();

	while (!candy::coreProxy::EntryPoint::IsEndMainLoopProxy())
	{
		candy::coreProxy::EntryPoint::MainLoopProxy();
	}

	candy::coreProxy::EntryPoint::PreCleanupProxy();
	
	ENTRY_POINT_CLEANUP();

	candy::coreProxy::EntryPoint::PostCleanupProxy();

	RETURN_ENTRY_POINT();
}
