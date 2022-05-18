#ifndef CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H
#define CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/Handle/GPU/GraphicDescriptorGpuHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DescriptorGpuHandle : public Impl::DescriptorGpuHandleImpl
	{

	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H
