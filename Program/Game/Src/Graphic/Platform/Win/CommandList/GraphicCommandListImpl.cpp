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

	void CommandListImpl::setRootSignature(ID3D12RootSignature* const _rootSignature)
	{
		m_CommandList->SetGraphicsRootSignature(_rootSignature);
	}

	void CommandListImpl::setPipeline(ID3D12PipelineState* const _pipeline)
	{
		m_CommandList->SetPipelineState(_pipeline);
	}

	void CommandListImpl::setPrimitiveTopology(const PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
	{
		m_CommandList->IASetPrimitiveTopology(ConvPrimitiveTopology(_primitiveTopologyType));
	}

	void CommandListImpl::setVertexBuffers(const D3D12_VERTEX_BUFFER_VIEW* const _vertexBufferView)
	{
		m_CommandList->IASetVertexBuffers(0, 1, _vertexBufferView);
	}

	void CommandListImpl::setIndexBuffer(const D3D12_INDEX_BUFFER_VIEW* const _indexBufferView)
	{
		m_CommandList->IASetIndexBuffer(_indexBufferView);
	}

	void CommandListImpl::setDescriptor(ID3D12DescriptorHeap* const _descriptor)
	{
		m_CommandList->SetDescriptorHeaps(1, &_descriptor);
	}

	void CommandListImpl::setDescriptorTable(const s32 _rootParameterIndex, const D3D12_GPU_DESCRIPTOR_HANDLE& _descriptorCpuHandle)
	{
		m_CommandList->SetGraphicsRootDescriptorTable(_rootParameterIndex, _descriptorCpuHandle);
	}

	void CommandListImpl::drawIndexedInstanced(const u32 _indexCountPerInstance, const u32 _instanceCount,
		const u32 _startIndexLocation, const u32 _baseVertexLocation, const u32 _startInstanceLocation)
	{
		m_CommandList->DrawIndexedInstanced(_indexCountPerInstance, _instanceCount,
			_startIndexLocation, _baseVertexLocation, _startInstanceLocation);
	}
}

CANDY_NAMESPACE_END
