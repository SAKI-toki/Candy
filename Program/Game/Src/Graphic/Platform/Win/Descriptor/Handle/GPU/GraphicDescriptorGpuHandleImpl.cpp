#include "GraphicDescriptorGpuHandleImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	DescriptorGpuHandleImpl::DescriptorGpuHandleImpl(const D3D12_GPU_DESCRIPTOR_HANDLE _gpuDescriptorHandle) :
		m_Handle{ _gpuDescriptorHandle }
	{

	}
}

CANDY_NAMESPACE_END
