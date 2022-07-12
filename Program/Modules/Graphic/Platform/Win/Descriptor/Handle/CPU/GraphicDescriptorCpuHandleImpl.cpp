#include "GraphicDescriptorCpuHandleImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	DescriptorCpuHandleImpl::DescriptorCpuHandleImpl(const D3D12_CPU_DESCRIPTOR_HANDLE _cpuDescriptorHandle):
		m_Handle{ _cpuDescriptorHandle }
	{

	}
}

CANDY_GRAPHIC_NAMESPACE_END
