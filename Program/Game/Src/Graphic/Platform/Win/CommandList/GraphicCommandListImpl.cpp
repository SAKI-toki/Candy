#include "GraphicCommandListImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandListImpl::startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount)
	{
		const auto CommandListType = ConvCommandListType(_commandListType);

		m_CommandAllocators.clear();
		m_CommandAllocators.resize(_backBufferCount);
		for (s32 i = 0; i < _backBufferCount; ++i)
		{
			CANDY_ASSERT_HRESULT(_device->CreateCommandAllocator(CommandListType,
				IID_PPV_ARGS(m_CommandAllocators[i].GetAddressOf())));
		}
		CANDY_ASSERT_HRESULT(_device->CreateCommandList(0, CommandListType,
			m_CommandAllocators[0].Get(), nullptr, IID_PPV_ARGS(m_CommandList.GetAddressOf())));
	}

	void CommandListImpl::cleanup()
	{
		m_CommandList.Reset();
		for (auto& commandAllocator : m_CommandAllocators)commandAllocator.Reset();
		m_CommandAllocators.clear();
	}

	void CommandListImpl::drawBegin(const s32 _backBufferIndex)
	{
		CANDY_ASSERT_HRESULT(m_CommandList->Reset(m_CommandAllocators[_backBufferIndex].Get(), nullptr));
	}

	void CommandListImpl::close()
	{
		CANDY_ASSERT_HRESULT(m_CommandList->Close());
	}

	void CommandListImpl::setViewport(const D3D12_VIEWPORT* const _viewport)
	{
		m_CommandList->RSSetViewports(1, _viewport);
	}

	void CommandListImpl::setScissorRect(const D3D12_RECT* const _scissorRect)
	{
		m_CommandList->RSSetScissorRects(1, _scissorRect);
	}

	void CommandListImpl::setRenderTargets(const D3D12_CPU_DESCRIPTOR_HANDLE* const _rtDescriptorCpuHandle,
		const s32 _renderTargetCount, const D3D12_CPU_DESCRIPTOR_HANDLE* const _dsDescriptorCpuHandle)
	{
		m_CommandList->OMSetRenderTargets(_renderTargetCount, _rtDescriptorCpuHandle, true, _dsDescriptorCpuHandle);
	}

	void CommandListImpl::clearRenderTarget(const D3D12_CPU_DESCRIPTOR_HANDLE& _rtDescriptorCpuHandle, const Vec4 _color)
	{
		m_CommandList->ClearRenderTargetView(_rtDescriptorCpuHandle, _color.m_f32Array, 0, nullptr);
	}
}

CANDY_NAMESPACE_END
