#include "GraphicDescriptorImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void DescriptorImpl::startup(ID3D12Device* const _device, const DESCRIPTOR_TYPE _descriptorType, const s32 _count)
	{
		m_Type = ConvDescriptorType(_descriptorType);

		D3D12_DESCRIPTOR_HEAP_DESC desc{};
		desc.NumDescriptors = _count;
		desc.Type = m_Type;
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

	void DescriptorImpl::bindingRenderTarget(ID3D12Device* const _device, ID3D12Resource* const _buffer, const s32 _index)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		descriptorHandle.ptr += GetDesciptorHandleIncrementSize(m_Type) * _index;

		D3D12_RENDER_TARGET_VIEW_DESC rtv_desc{};
		rtv_desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
		_device->CreateRenderTargetView(_buffer, &rtv_desc, descriptorHandle);
	}

	DescriptorCpuHandleImpl DescriptorImpl::getCpuHandle(const s32 _offsetIndex)const
	{
		auto handle = m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart();
		handle.ptr += GetDesciptorHandleIncrementSize(m_Type) * _offsetIndex;
		return DescriptorCpuHandleImpl{ handle };
	}

	DescriptorGpuHandleImpl DescriptorImpl::getGpuHandle(const s32 _offsetIndex)const
	{
		auto handle = m_DescriptorHeap->GetGPUDescriptorHandleForHeapStart();
		handle.ptr += GetDesciptorHandleIncrementSize(m_Type) * _offsetIndex;
		return DescriptorGpuHandleImpl{ handle };
	}
}

CANDY_NAMESPACE_END
