#ifndef CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H
#define CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/Handle/GPU/GraphicDescriptorGpuHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class DescriptorGpuHandle : public impl::DescriptorGpuHandleImpl
{

};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_GPU_HANDLE_H
