#include "GraphicDeviceImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void DeviceImpl::startup()
	{
		u32 factoryFlag = 0;

#if BUILD_DEBUG
		//デバッグレイヤの有効
		core::ComPtr<ID3D12Debug> debug;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(debug.GetAddressOf()))))
		{
			debug->EnableDebugLayer();
		}
		factoryFlag |= DXGI_CREATE_FACTORY_DEBUG;
#endif // BUILD_DEBUG

		CANDY_ASSERT_HRESULT(CreateDXGIFactory2(factoryFlag, IID_PPV_ARGS(m_Factory.GetAddressOf())));

		core::ComPtr<IDXGIAdapter1> adapter;
		for (u32 i = 0; ; ++i)
		{
			if (FAILED(m_Factory->EnumAdapterByGpuPreference(i, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(adapter.GetAddressOf()))))break;	
			DXGI_ADAPTER_DESC1 desc;
			adapter->GetDesc1(&desc);
			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)continue;
			if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
		}

		CANDY_ASSERT_HRESULT(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(m_Device.GetAddressOf())));
	}

	void DeviceImpl::cleanup()
	{
		m_Device.Reset();
	}
}

CANDY_GRAPHIC_NAMESPACE_END
