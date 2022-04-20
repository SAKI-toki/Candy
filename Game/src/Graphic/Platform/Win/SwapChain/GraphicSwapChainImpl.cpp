#include "GraphicSwapChainImpl.h"
#include <Hardware/Platform/Win/HardwareImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void SwapChainImpl::startup(IDXGIFactory6* const _factory, ID3D12CommandQueue* const _commandQueue,
		const TEXTURE_FORMAT _textureFormat, const s32 _frameCount, const s32 _width, const s32 _height)
	{
		DXGI_SWAP_CHAIN_DESC1 desc{};
		desc.BufferCount = _frameCount;
		desc.Width = _width;
		desc.Height = _height;
		desc.Format = ConvTextureFormat(_textureFormat);
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		desc.SampleDesc.Count = 1;

		ComPtr<IDXGISwapChain1> swapChainForHwnd;
		const HWND hwnd = Hardware::Impl::GetHwnd();
		
		CANDY_ASSERT_HRESULT(_factory->CreateSwapChainForHwnd(_commandQueue, hwnd, &desc, nullptr, nullptr, &swapChainForHwnd));
		CANDY_ASSERT_HRESULT(_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER));
		CANDY_ASSERT_HRESULT(swapChainForHwnd.As(&m_SwapChain));

		m_BackBuffers.clear();
		m_BackBuffers.resize(_frameCount);
		for (s32 i = 0; i < _frameCount; ++i)
		{
			CANDY_ASSERT_HRESULT(m_SwapChain->GetBuffer(i, IID_PPV_ARGS(m_BackBuffers[i].GetAddressOf())));
		}
	}

	void SwapChainImpl::cleanup()
	{
		m_SwapChain.Reset();
	}

	void SwapChainImpl::present(const s32 _syncInterval)
	{
		CANDY_ASSERT_HRESULT(m_SwapChain->Present(_syncInterval, 0));
	}
}

CANDY_NAMESPACE_END
