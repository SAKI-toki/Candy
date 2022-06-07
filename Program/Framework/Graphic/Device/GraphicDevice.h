#ifndef CANDY_GRAPHIC_DEVICE_H
#define CANDY_GRAPHIC_DEVICE_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Device/GraphicDeviceImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Device : public Impl::DeviceImpl
	{
	public:
		void startup();
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEVICE_H
