#ifndef CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H
#define CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class SwapChainImpl
	{
	protected:
		void startup(IDXGIFactory6* const _factory, ID3D12CommandQueue* const _commandQueue,
			const types::GRAPHIC_FORMAT _graphicFormat, const s32 _backBufferCount, const s32 _width, const s32 _height);
		void cleanup();

		void present(const s32 _syncInterval);
		s32 getBackBufferIndex();

	public:
		IDXGISwapChain3* getSwapChain()const { return m_SwapChain.Get(); }

	private:
		ComPtr<IDXGISwapChain3> m_SwapChain;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H
