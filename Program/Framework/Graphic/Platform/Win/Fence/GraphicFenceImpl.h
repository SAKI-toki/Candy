#ifndef CANDY_GRAPHIC_FENCE_IMPL_H
#define CANDY_GRAPHIC_FENCE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class FenceImpl
	{
	protected:
		void startup(ID3D12Device* const _device);
		void cleanup();

		void signalFromCpu(const u64 _value);
		void signalFromGpu(ID3D12CommandQueue* const _commandQueue, const u64 _value);
		void waitCpu(const u64 _value);
		void waitGpu(ID3D12CommandQueue* const _commandQueue, const u64 _value);
		u64 getCompletedValue();

	private:
		ComPtr<ID3D12Fence> m_Fence;
		HANDLE m_FenceEvent;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_FENCE_IMPL_H
