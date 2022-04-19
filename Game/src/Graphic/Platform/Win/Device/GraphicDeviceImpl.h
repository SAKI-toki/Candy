#ifndef CANDY_GRAPHIC_DEVICE_IMPL_H
#define CANDY_GRAPHIC_DEVICE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DeviceImpl
	{
	public:
		void startup();
		void cleanup();

		ID3D12Device* getDevice()const { return m_Device.Get(); }

	private:
		ComPtr<IDXGIFactory6> m_Factory;
		ComPtr<ID3D12Device> m_Device;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEVICE_IMPL_H
