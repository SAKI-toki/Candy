#ifndef CANDY_HARDWARE_H
#define CANDY_HARDWARE_H

#if PLATFORM_WIN
#include "Platform/Win/HardwareImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

namespace Hardware
{
	struct StartupInfo : Impl::StartupInfo
	{

	};

	void Startup(const StartupInfo& _startupInfo);
	void Cleanup();

	void Update();

	bool IsClose();
}

CANDY_NAMESPACE_END

#endif // CANDY_HARDWARE_H
