#ifndef CANDY_GRAPHIC_DESCRIPTOR_H
#define CANDY_GRAPHIC_DESCRIPTOR_H

#include <Graphic/GraphicInclude.h>

#include "Handle/CPU/GraphicDescriptorCpuHandle.h"
#include "Handle/GPU/GraphicDescriptorGpuHandle.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/GraphicDescriptorImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device;
class Buffer;

class Descriptor : public impl::DescriptorImpl
{
public:
	void startup(const Device& _device, const types::DESCRIPTOR_TYPE _descriptorType, const s32 _count);
	void cleanup();

	void bindingRenderTarget(const Device& _device, const s32 _index, const Buffer& _buffer, const types::GRAPHIC_FORMAT _graphicFormat);
	void bindingDepthStencil(const Device& _device, const s32 _index, const Buffer& _buffer, const types::GRAPHIC_FORMAT _graphicFormat);
	void bindingBackBuffer(const Device& _device, const s32 _index, const Buffer& _buffer);
	void bindingTexture2D(const Device& _device, const s32 _index,
		const Buffer& _buffer, const types::GRAPHIC_FORMAT _graphicFormat);
	void bindingConstantBuffer(const Device& _device, const u32 _index, const Buffer& _buffer,
		const u32 _offset, const u32 _size);

	DescriptorCpuHandle getCpuHandle(const s32 _offsetIndex)const;
	DescriptorGpuHandle getGpuHandle(const s32 _offsetIndex)const;
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_H
