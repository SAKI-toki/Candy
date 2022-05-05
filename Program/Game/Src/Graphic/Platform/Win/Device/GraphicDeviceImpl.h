#ifndef CANDY_GRAPHIC_DEVICE_IMPL_H
#define CANDY_GRAPHIC_DEVICE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DeviceImpl
	{
	protected:
		void startup();
		void cleanup();

	public:
		ID3D12Device* getDevice()const { return m_Device.Get(); }
		IDXGIFactory6* getFactory()const { return m_Factory.Get(); }

	private:
		ComPtr<IDXGIFactory6> m_Factory;
		ComPtr<ID3D12Device> m_Device;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEVICE_IMPL_H
