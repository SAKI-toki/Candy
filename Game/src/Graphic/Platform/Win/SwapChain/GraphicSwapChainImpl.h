#ifndef CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H
#define CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class SwapChainImpl
	{
	public:
		void startup(IDXGIFactory6* const _factory, ID3D12CommandQueue* const _commandQueue,
			const TEXTURE_FORMAT _textureFormat, const s32 _frameCount, const s32 _width, const s32 _height);
		void cleanup();

		void present(const s32 _syncInterval);

	private:
		ComPtr<IDXGISwapChain3> m_SwapChain;
		std::vector<ComPtr<ID3D12Resource>> m_BackBuffers;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_SWAP_CHAIN_IMPL_H
