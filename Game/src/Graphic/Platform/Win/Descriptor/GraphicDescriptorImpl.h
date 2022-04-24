#ifndef CANDY_GRAPHIC_DESCRIPTOR_IMPL_H
#define CANDY_GRAPHIC_DESCRIPTOR_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>
#include "Handle/CPU/GraphicDescriptorCpuHandleImpl.h"
#include "Handle/GPU/GraphicDescriptorGpuHandleImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DescriptorImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const DESCRIPTOR_TYPE _descriptorType, const s32 _count);
		void cleanup();

		void bindingRenderTarget(ID3D12Device* const _device, ID3D12Resource* const _buffer, const s32 _index);

		DescriptorCpuHandleImpl getCpuHandle(const s32 _offsetIndex)const;
		DescriptorGpuHandleImpl getGpuHandle(const s32 _offsetIndex)const;

	public:
		ID3D12DescriptorHeap* getDescriptor()const { return m_DescriptorHeap.Get(); }

	private:
		ComPtr<ID3D12DescriptorHeap> m_DescriptorHeap;
		D3D12_DESCRIPTOR_HEAP_TYPE m_Type;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_IMPL_H
