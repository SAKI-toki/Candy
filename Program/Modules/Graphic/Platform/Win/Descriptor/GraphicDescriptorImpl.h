#ifndef CANDY_GRAPHIC_DESCRIPTOR_IMPL_H
#define CANDY_GRAPHIC_DESCRIPTOR_IMPL_H

#include <Graphic/GraphicInclude.h>

#include "Handle/CPU/GraphicDescriptorCpuHandleImpl.h"
#include "Handle/GPU/GraphicDescriptorGpuHandleImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class DescriptorImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const types::DESCRIPTOR_TYPE _descriptorType, const s32 _count);
		void cleanup();

		void bindingRenderTarget(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer, const types::GRAPHIC_FORMAT _graphicFormat);
		void bindingDepthStencil(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer, const types::GRAPHIC_FORMAT _graphicFormat);
		void bindingBackBuffer(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer);
		void bindingTexture2D(ID3D12Device* const _device, const s32 _index, ID3D12Resource* const _buffer, 
			const types::GRAPHIC_FORMAT _graphicFormat, const s32 _mipMapCount);
		void bindingConstantBuffer(ID3D12Device* const _device, const u32 _index,
			ID3D12Resource* const _buffer, const u32 _offset, const u32 _size);

		DescriptorCpuHandleImpl getCpuHandle(const s32 _offsetIndex)const;
		DescriptorGpuHandleImpl getGpuHandle(const s32 _offsetIndex)const;

	public:
		ID3D12DescriptorHeap* getDescriptor()const { return m_DescriptorHeap.Get(); }
		types::DESCRIPTOR_TYPE getDescriptorType()const { return m_DescriptorType; }
		s32 getDescriptorCount()const { return m_DescriptorCount; }

	private:
		ComPtr<ID3D12DescriptorHeap> m_DescriptorHeap;
		types::DESCRIPTOR_TYPE m_DescriptorType{};
		D3D12_DESCRIPTOR_HEAP_TYPE m_RealDescriptorType{};
		s32 m_DescriptorCount{};
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_IMPL_H
