#ifndef CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_IMPL_H
#define CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class DescriptorGpuHandleImpl
	{
	public:
		explicit DescriptorGpuHandleImpl(const D3D12_GPU_DESCRIPTOR_HANDLE _gpuDescriptorHandle);

		D3D12_GPU_DESCRIPTOR_HANDLE getHandle()const { return m_Handle; }
		const D3D12_GPU_DESCRIPTOR_HANDLE* getHandleAddress()const { return &m_Handle; }

	private:
		D3D12_GPU_DESCRIPTOR_HANDLE m_Handle;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_IMPL_H
