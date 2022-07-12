#ifndef CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H
#define CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/Handle/CPU/GraphicDescriptorCpuHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class DescriptorCpuHandle : public impl::DescriptorCpuHandleImpl
{

};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H
