#include "GraphicBufferImpl.h"
#include "StartupInfo/GraphicBufferStartupInfoImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void BufferImpl::startup(ID3D12Device* const _device, const BufferStartupInfoImpl& _startupInfo)
	{
		m_ResourceState = _startupInfo.getInitState();

		CANDY_ASSERT_HRESULT(_device->CreateCommittedResource(_startupInfo.getHeapPropertiesAddress(), D3D12_HEAP_FLAG_NONE,
			_startupInfo.getResourceDescAddress(), m_ResourceState, _startupInfo.getClearValueAddress(), IID_PPV_ARGS(m_Buffer.GetAddressOf())));
	}

	void BufferImpl::startupBackBuffer(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex)
	{
		CANDY_ASSERT_HRESULT(_swapChain->GetBuffer(_backBufferIndex, IID_PPV_ARGS(m_Buffer.GetAddressOf())));
	}

	void BufferImpl::cleanup()
	{
		m_Buffer.Reset();
	}

	void BufferImpl::translationBarrier(ID3D12GraphicsCommandList* const _commandList, const types::BARRIER_STATE _nextBarrierState)
	{
		const auto NextBarrierState = ConvBarrierState(_nextBarrierState);
		if (NextBarrierState == m_ResourceState)return;

		D3D12_RESOURCE_BARRIER barrier{};
		barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		barrier.Transition.pResource = m_Buffer.Get();
		barrier.Transition.StateBefore = m_ResourceState;
		barrier.Transition.StateAfter = NextBarrierState;
		barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

		m_ResourceState = NextBarrierState;

		_commandList->ResourceBarrier(1, &barrier);
	}

	void BufferImpl::store(const std::byte* const _buf, const u64 _size, const u64 _offset)
	{
		std::byte* pData{};
		CANDY_ASSERT_HRESULT(m_Buffer->Map(0, nullptr, reinterpret_cast<void**>(&pData)));
		memcpy(pData + _offset, _buf, _size);
		m_Buffer->Unmap(0, nullptr);
	}
}

CANDY_GRAPHIC_NAMESPACE_END
