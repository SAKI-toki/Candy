/*****************************************************************//**
 * \file   Main.cpp
 * \brief  エントリーポイント
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#if PLATFORM_WIN
#include "Platform/Win/MainImpl.h"
#endif // PLATFORM_WIN

#include <Hardware/Hardware.h>
#include <Flow/Main/MainFlow.h>

// エントリーポイント
ENTRY_POINT_MAIN()
{
	ENTRY_POINT_STARTUP();

	candy::MainFlow::Startup();
	while (!candy::MainFlow::IsEnd())
	{
		candy::MainFlow::Update();
	}
	candy::MainFlow::Cleanup();

	ENTRY_POINT_CLEANUP();

	RETURN_ENTRY_POINT();
}
