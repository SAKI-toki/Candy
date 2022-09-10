#include "GraphicDescriptorImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void DescriptorImpl::startup(ID3D12Device* const _device, const types::DESCRIPTOR_TYPE _descriptorType, const s32 _count)
	{
		m_DescriptorType = _descriptorType;
		m_RealDescriptorType = ConvDescriptorType(_descriptorType);
		m_DescriptorCount = _count;

		D3D12_DESCRIPTOR_HEAP_DESC desc{};
		desc.NumDescriptors = m_DescriptorCount;
		desc.Type = m_RealDescriptorType;
		desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
		switch (desc.Type)
		{
		case D3D12_DESCRIPTOR_HEAP_TYPE_RTV:
		case D3D12_DESCRIPTOR_HEAP_TYPE_DSV:
			desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
			break;
		}

		CANDY_ASSERT_HRESULT(_device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(m_DescriptorHeap.GetAddressOf())));
	}

	void DescriptorImpl::cleanup()
	{
		m_DescriptorHeap.Reset();
	}

	void DescriptorImpl::bindingRenderTarget(ID3D12Device* const _device, const s32 _index, 
		ID3D12Resource* const _buffer, const types::GRAPHIC_FORMAT _graphicFormat)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _index;

		D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};
		rtvDesc.Format = ConvGraphicFormat(_graphicFormat);
		rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
		rtvDesc.Texture2D.MipSlice = 0;

		_device->CreateRenderTargetView(_buffer, &rtvDesc, descriptorHandle);
	}

	void DescriptorImpl::bindingDepthStencil(ID3D12Device* const _device, const s32 _index, 
		ID3D12Resource* const _buffer, const types::GRAPHIC_FORMAT _graphicFormat)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _index;

		D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc{};
		dsvDesc.Format = ConvGraphicFormat(_graphicFormat);
		dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
		dsvDesc.Texture2D.MipSlice = 0;

		_device->CreateDepthStencilView(_buffer, &dsvDesc, descriptorHandle);
	}

	void DescriptorImpl::bindingBackBuffer(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _index;

		_device->CreateRenderTargetView(_buffer, nullptr, descriptorHandle);
	}

	void DescriptorImpl::bindingTexture2D(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer, 
		const types::GRAPHIC_FORMAT _graphicFormat, const s32 _mipMapCount)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _index;

		D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
		srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
		srvDesc.Format = ConvGraphicFormat(_graphicFormat);
		srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = static_cast<UINT>(_mipMapCount);

		_device->CreateShaderResourceView(_buffer, &srvDesc, descriptorHandle);
	}

	void DescriptorImpl::bindingConstantBuffer(ID3D12Device* const _device, const u32 _index,
		ID3D12Resource* const _buffer, const u32 _offset, const u32 _size)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _index;

		D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc{};
		cbvDesc.BufferLocation = _buffer->GetGPUVirtualAddress() + _offset;
		cbvDesc.SizeInBytes = _size;

		_device->CreateConstantBufferView(&cbvDesc, descriptorHandle);
	}

	DescriptorCpuHandleImpl DescriptorImpl::getCpuHandle(const s32 _offsetIndex)const
	{
		auto handle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		handle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _offsetIndex;
		return DescriptorCpuHandleImpl{ handle };
	}

	DescriptorGpuHandleImpl DescriptorImpl::getGpuHandle(const s32 _offsetIndex)const
	{
		auto handle = m_DescriptorHeap->GetGPUDescriptorHandleForHeapStart();
		handle.ptr += GetDesciptorHandleIncrementSize(m_RealDescriptorType) * _offsetIndex;
		return DescriptorGpuHandleImpl{ handle };
	}
}

CANDY_GRAPHIC_NAMESPACE_END
