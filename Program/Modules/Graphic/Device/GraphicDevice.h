#ifndef CANDY_GRAPHIC_DEVICE_H
#define CANDY_GRAPHIC_DEVICE_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Device/GraphicDeviceImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device : public impl::DeviceImpl
{
public:
	void startup();
	void cleanup();
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEVICE_H
