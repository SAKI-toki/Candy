#ifndef CANDY_GRAPHIC_DESCRIPTOR_H
#define CANDY_GRAPHIC_DESCRIPTOR_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include "Handle/CPU/GraphicDescriptorCpuHandle.h"
#include "Handle/GPU/GraphicDescriptorGpuHandle.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/GraphicDescriptorImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Descriptor : public DescriptorImpl
	{
	public:
		void startup(const Device& _device, const DESCRIPTOR_TYPE _descriptorType, const s32 _count);
		void cleanup();

		void bindingRenderTarget(const Device& _device, const Buffer& _buffer, const s32 _index);

		DescriptorCpuHandle getCpuHandle(const s32 _offsetIndex)const;
		DescriptorGpuHandle getGpuHandle(const s32 _offsetIndex)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_H
