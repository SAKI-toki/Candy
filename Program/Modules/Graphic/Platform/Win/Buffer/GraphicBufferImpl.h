#ifndef CANDY_GRAPHIC_BUFFER_IMPL_H
#define CANDY_GRAPHIC_BUFFER_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class BufferStartupInfoImpl;

	class BufferImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const BufferStartupInfoImpl& _startupInfo);
		void startupBackBuffer(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex);

		void cleanup();

		void translationBarrier(ID3D12GraphicsCommandList* const _graphicCommandList, 
			const types::BARRIER_STATE _prevBarrierState, const types::BARRIER_STATE _nextBarrierState);

		void store(const std::byte* const _buf, const u64 _size,const u64 _offset);

		void setName(const std::string_view _name);

	public:
		ID3D12Resource* getBuffer()const { return m_Buffer.Get(); }
		D3D12_GPU_VIRTUAL_ADDRESS getGpuVirtualAddress()const { return m_Buffer->GetGPUVirtualAddress(); }

	private:
		ComPtr<ID3D12Resource> m_Buffer;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_IMPL_H
