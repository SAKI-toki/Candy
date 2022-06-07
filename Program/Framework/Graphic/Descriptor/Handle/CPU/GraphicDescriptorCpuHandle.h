#ifndef CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H
#define CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Descriptor/Handle/CPU/GraphicDescriptorCpuHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DescriptorCpuHandle : public Impl::DescriptorCpuHandleImpl
	{

	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_H
