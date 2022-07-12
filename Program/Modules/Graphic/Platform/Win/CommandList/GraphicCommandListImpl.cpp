#include "GraphicCommandListImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void CommandListImpl::startup(ID3D12Device* const _device, const types::COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount)
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

	void CommandListImpl::preDraw(const s32 _backBufferIndex)
	{
		m_CommandAllocators[_backBufferIndex]->Reset();
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

	void CommandListImpl::clearDepthStencil(const D3D12_CPU_DESCRIPTOR_HANDLE& _dsDescriptorCpuHandle,
		const bool _clearDepth, const f32 _depth, const bool _clearStencil, const u32 _stencil)
	{
		D3D12_CLEAR_FLAGS flag = D3D12_CLEAR_FLAGS(0);
		if (_clearDepth)flag |= D3D12_CLEAR_FLAG_DEPTH;
		if (_clearStencil)flag |= D3D12_CLEAR_FLAG_STENCIL;
		m_CommandList->ClearDepthStencilView(_dsDescriptorCpuHandle, flag, _depth, static_cast<u8>(_stencil), 0, nullptr);
	}

	void CommandListImpl::setRootSignature(ID3D12RootSignature* const _rootSignature)
	{
		m_CommandList->SetGraphicsRootSignature(_rootSignature);
	}

	void CommandListImpl::setPipeline(ID3D12PipelineState* const _pipeline)
	{
		m_CommandList->SetPipelineState(_pipeline);
	}

	void CommandListImpl::setPrimitiveTopology(const types::PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
	{
		m_CommandList->IASetPrimitiveTopology(ConvPrimitiveTopology(_primitiveTopologyType));
	}

	void CommandListImpl::setVertexBuffer(const s32 _index, const D3D12_VERTEX_BUFFER_VIEW& _vertexBufferView)
	{
		m_VertexBufferViews[_index] = _vertexBufferView;
	}

	void CommandListImpl::registVertexBuffers(const s32 _count)
	{
		m_CommandList->IASetVertexBuffers(0, _count, m_VertexBufferViews);
	}

	void CommandListImpl::setIndexBuffer(const D3D12_INDEX_BUFFER_VIEW* const _indexBufferView)
	{
		m_CommandList->IASetIndexBuffer(_indexBufferView);
	}

	void CommandListImpl::setDescriptor(const s32 _index, ID3D12DescriptorHeap* const _descriptor)
	{
		m_DescriptorHeaps[_index] = _descriptor;
	}

	void CommandListImpl::registDescriptors(const s32 _count, const s32 _offsetIndex)
	{
		m_CommandList->SetDescriptorHeaps(_count, m_DescriptorHeaps + _offsetIndex);
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

	void CommandListImpl::copyTexture(ID3D12Device* const _device, ID3D12Resource* const _dstBuffer, ID3D12Resource* const _srcBuffer)
	{
		D3D12_TEXTURE_COPY_LOCATION  dstTextureCopyLocation{};
		dstTextureCopyLocation.pResource = _dstBuffer;
		dstTextureCopyLocation.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
		dstTextureCopyLocation.SubresourceIndex = 0;

		D3D12_RESOURCE_DESC dstBufferDesc = _dstBuffer->GetDesc();
		D3D12_PLACED_SUBRESOURCE_FOOTPRINT  placedSubresourceFootprint;
		u64 totalBytes = 0;
		_device->GetCopyableFootprints(&dstBufferDesc, 0, 1, 0, &placedSubresourceFootprint, nullptr, nullptr, &totalBytes);

		D3D12_TEXTURE_COPY_LOCATION  srcTextureCopyLocation{};
		srcTextureCopyLocation.pResource = _srcBuffer;
		srcTextureCopyLocation.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
		srcTextureCopyLocation.PlacedFootprint = placedSubresourceFootprint;
		m_CommandList->CopyTextureRegion(&dstTextureCopyLocation, 0, 0, 0, &srcTextureCopyLocation, nullptr);
	}
}

CANDY_GRAPHIC_NAMESPACE_END
