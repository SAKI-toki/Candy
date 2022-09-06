#include "GraphicBufferImpl.h"
#include "StartupInfo/GraphicBufferStartupInfoImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void BufferImpl::startup(ID3D12Device* const _device, const BufferStartupInfoImpl& _startupInfo)
	{
		CANDY_ASSERT_HRESULT(_device->CreateCommittedResource(_startupInfo.getHeapPropertiesAddress(), D3D12_HEAP_FLAG_NONE,
			_startupInfo.getResourceDescAddress(), _startupInfo.getInitBarrierState(), _startupInfo.getClearValueAddress(), IID_PPV_ARGS(m_Buffer.GetAddressOf())));
	}

	void BufferImpl::startupBackBuffer(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex)
	{
		CANDY_ASSERT_HRESULT(_swapChain->GetBuffer(_backBufferIndex, IID_PPV_ARGS(m_Buffer.GetAddressOf())));
	}

	void BufferImpl::cleanup()
	{
		m_Buffer.Reset();
	}

	void BufferImpl::translationBarrier(ID3D12GraphicsCommandList* const _commandList, 
		const types::BARRIER_STATE _prevBarrierState, const types::BARRIER_STATE _nextBarrierState)
	{
		
		const auto prevBarrierState = ConvBarrierState(_prevBarrierState);
		const auto nextBarrierState = ConvBarrierState(_nextBarrierState);

		D3D12_RESOURCE_BARRIER barrier{};
		barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		barrier.Transition.pResource = m_Buffer.Get();
		barrier.Transition.StateBefore = prevBarrierState;
		barrier.Transition.StateAfter = nextBarrierState;
		barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

		_commandList->ResourceBarrier(1, &barrier);
	}

	void BufferImpl::store(const std::byte* const _buf, const u64 _size, const u64 _offset)
	{
		std::byte* pData{};
		CANDY_ASSERT_HRESULT(m_Buffer->Map(0, nullptr, reinterpret_cast<void**>(&pData)));
		memcpy(pData + _offset, _buf, _size);
		m_Buffer->Unmap(0, nullptr);
	}

	void BufferImpl::setName(const std::string_view _name)
	{
		m_Buffer->SetName(core::StringSystem::ConvertMultiByteToWideCharSJIS(_name).data());
	}
}

CANDY_GRAPHIC_NAMESPACE_END
