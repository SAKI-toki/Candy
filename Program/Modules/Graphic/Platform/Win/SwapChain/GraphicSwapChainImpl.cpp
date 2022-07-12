#include "GraphicSwapChainImpl.h"
#include <Core/Platform/Win/Hardware/HardwareImpl.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void SwapChainImpl::startup(IDXGIFactory6* const _factory, ID3D12CommandQueue* const _commandQueue,
		const types::GRAPHIC_FORMAT _graphicFormat, const s32 _backBufferCount, const s32 _width, const s32 _height)
	{
		DXGI_SWAP_CHAIN_DESC1 desc{};
		desc.BufferCount = _backBufferCount;
		desc.Width = _width;
		desc.Height = _height;
		desc.Format = ConvGraphicFormat(_graphicFormat);
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		desc.SampleDesc.Count = 1;

		core::ComPtr<IDXGISwapChain1> swapChainForHwnd;
		const HWND hwnd = core::Hardware::GetHwnd();
		
		CANDY_ASSERT_HRESULT(_factory->CreateSwapChainForHwnd(_commandQueue, hwnd, &desc, nullptr, nullptr, &swapChainForHwnd));
		CANDY_ASSERT_HRESULT(_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER));
		CANDY_ASSERT_HRESULT(swapChainForHwnd.As(&m_SwapChain));
	}

	void SwapChainImpl::cleanup()
	{
		m_SwapChain.Reset();
	}

	void SwapChainImpl::present(const s32 _syncInterval)
	{
		CANDY_ASSERT_HRESULT(m_SwapChain->Present(_syncInterval, 0));
	}

	s32 SwapChainImpl::getBackBufferIndex()
	{
		return m_SwapChain->GetCurrentBackBufferIndex();
	}
}

CANDY_GRAPHIC_NAMESPACE_END
