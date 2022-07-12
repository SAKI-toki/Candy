#include "GraphicDevice.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void Device::startup()
{
	DeviceImpl::startup();
}

void Device::cleanup()
{
	DeviceImpl::cleanup();
}

CANDY_GRAPHIC_NAMESPACE_END
