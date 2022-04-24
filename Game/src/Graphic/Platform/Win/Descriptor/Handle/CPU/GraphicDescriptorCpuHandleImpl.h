#ifndef CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_IMPL_H
#define CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class DescriptorCpuHandleImpl
	{
	public:
		explicit DescriptorCpuHandleImpl(const D3D12_CPU_DESCRIPTOR_HANDLE _cpuDescriptorHandle);

		const D3D12_CPU_DESCRIPTOR_HANDLE* getHandle()const { return &m_Handle; }

	private:
		D3D12_CPU_DESCRIPTOR_HANDLE m_Handle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DESCRIPTOR_CPU_HANDLE_IMPL_H
