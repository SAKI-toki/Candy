#ifndef CANDY_GRAPHIC_BUFFER_IMPL_H
#define CANDY_GRAPHIC_BUFFER_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class BufferImpl
	{
	protected:
		void startupRenderTarget(ID3D12Device* const _device, const GRAPHIC_FORMAT _graphicFormat, const s32 _width, const s32 _height);
		void startupBackBuffer(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex);

		void cleanup();

		void translationBarrier(ID3D12GraphicsCommandList* const _graphicCommandList, const BARRIER_STATE _nextBarrierState);

	public:
		ID3D12Resource* getBuffer()const { return m_Buffer.Get(); }

	private:
		ComPtr<ID3D12Resource> m_Buffer;
		D3D12_RESOURCE_STATES m_ResourceState;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_IMPL_H
