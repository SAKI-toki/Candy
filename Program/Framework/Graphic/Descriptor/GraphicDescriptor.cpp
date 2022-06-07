#include "GraphicDescriptor.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Buffer/GraphicBuffer.h>

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

	void Descriptor::bindingRenderTarget(const Device& _device, const s32 _index, const Buffer& _buffer, const GRAPHIC_FORMAT _graphicFormat)
	{
		DescriptorImpl::bindingRenderTarget(_device.getDevice(), _index, _buffer.getBuffer(), _graphicFormat);
	}

	void Descriptor::bindingDepthStencil(const Device& _device, const s32 _index, const Buffer& _buffer, const GRAPHIC_FORMAT _graphicFormat)
	{
		DescriptorImpl::bindingDepthStencil(_device.getDevice(), _index, _buffer.getBuffer(), _graphicFormat);
	}

	void Descriptor::bindingBackBuffer(const Device& _device, const s32 _index, const Buffer& _buffer)
	{
		DescriptorImpl::bindingBackBuffer(_device.getDevice(), _index, _buffer.getBuffer());
	}
	
	void Descriptor::bindingTexture2D(const Device& _device, const s32 _index,
		const Buffer& _buffer, const GRAPHIC_FORMAT _graphicFormat)
	{
		DescriptorImpl::bindingTexture2D(_device.getDevice(), _index, _buffer.getBuffer(), _graphicFormat);
	}

	void Descriptor::bindingConstantBuffer(const Device& _device, const u32 _index,
		const Buffer& _buffer, const u32 _offset, const u32 _size)
	{
		DescriptorImpl::bindingConstantBuffer(_device.getDevice(), _index, _buffer.getBuffer(), _offset, _size);
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
