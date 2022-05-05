#include "Hardware.h"

CANDY_NAMESPACE_BEGIN

void Hardware::Startup(const StartupInfo& _startupInfo)
{
	Impl::Startup(_startupInfo);
}

void Hardware::Cleanup()
{
	Impl::Cleanup();
}

void Hardware::Update()
{
	Impl::Update();
}

bool Hardware::IsClose()
{
	return Impl::IsClose();
}

CANDY_NAMESPACE_END
