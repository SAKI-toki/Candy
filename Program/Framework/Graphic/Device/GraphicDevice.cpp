#include "GraphicDevice.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Device::startup()
	{
		DeviceImpl::startup();
	}

	void Device::cleanup()
	{
		DeviceImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
