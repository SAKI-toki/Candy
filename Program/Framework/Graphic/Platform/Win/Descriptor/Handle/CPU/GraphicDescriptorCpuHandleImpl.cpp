#include "GraphicDescriptorCpuHandleImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	DescriptorCpuHandleImpl::DescriptorCpuHandleImpl(const D3D12_CPU_DESCRIPTOR_HANDLE _cpuDescriptorHandle):
		m_Handle{ _cpuDescriptorHandle }
	{

	}
}

CANDY_NAMESPACE_END
