#include "GraphicDescriptorGpuHandleImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	DescriptorGpuHandleImpl::DescriptorGpuHandleImpl(const D3D12_GPU_DESCRIPTOR_HANDLE _gpuDescriptorHandle) :
		m_Handle{ _gpuDescriptorHandle }
	{

	}
}

CANDY_GRAPHIC_NAMESPACE_END
