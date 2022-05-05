#include "GraphicDescriptor.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Descriptor::startup(const Device& _device, const DESCRIPTOR_TYPE _descriptorType, const s32 _count)
	{
		DescriptorImpl::startup(_device.getDevice(), _descriptorType, _count);
	}

	void Descriptor::cleanup()
	{
		DescriptorImpl::cleanup();
	}

	void Descriptor::bindingRenderTarget(const Device& _device, const Buffer& _buffer, const s32 _index)
	{
		DescriptorImpl::bindingRenderTarget(_device.getDevice(), _buffer.getBuffer(), _index);
	}

	DescriptorCpuHandle Descriptor::getCpuHandle(const s32 _offsetIndex)const
	{
		return DescriptorCpuHandle{ DescriptorImpl::getCpuHandle(_offsetIndex) };
	}

	DescriptorGpuHandle Descriptor::getGpuHandle(const s32 _offsetIndex)const
	{
		return DescriptorGpuHandle{ DescriptorImpl::getGpuHandle(_offsetIndex) };
	}
}

CANDY_NAMESPACE_END
