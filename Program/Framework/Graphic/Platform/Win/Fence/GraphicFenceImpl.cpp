#include "GraphicFenceImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	void FenceImpl::startup(ID3D12Device* const _device)
	{
		CANDY_ASSERT_HRESULT(_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(m_Fence.GetAddressOf())));
		m_FenceEvent = ::CreateEvent(nullptr, false, false, nullptr);
		CANDY_ASSERT(m_FenceEvent != nullptr);
	}

	void FenceImpl::cleanup()
	{
		m_Fence.Reset();
	}

	void FenceImpl::signalFromCpu(const u64 _value)
	{
		m_Fence->Signal(_value);
	}

	void FenceImpl::signalFromGpu(ID3D12CommandQueue* const _commandQueue, const u64 _value)
	{
		_commandQueue->Signal(m_Fence.Get(), _value);
	}

	void FenceImpl::waitCpu(const u64 _value)
	{
		CANDY_ASSERT_HRESULT(m_Fence->SetEventOnCompletion(_value, m_FenceEvent));
		WaitForSingleObjectEx(m_FenceEvent, INFINITE, false);
	}

	void FenceImpl::waitGpu(ID3D12CommandQueue* const _commandQueue, const u64 _value)
	{
		CANDY_ASSERT_HRESULT(_commandQueue->Wait(m_Fence.Get(), _value));
	}

	u64 FenceImpl::getCompletedValue()
	{
		return m_Fence->GetCompletedValue();
	}
}

CANDY_NAMESPACE_END
