#ifndef CANDY_GRAPHIC_BACK_BUFFER_IMPL_H
#define CANDY_GRAPHIC_BACK_BUFFER_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>
#include <Graphic/Platform/Win/SwapChain/GraphicSwapChainImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class BackBufferImpl : public BufferImpl
	{
	public:
		void startup(IDXGISwapChain* const _swapChain, const s32 _backBufferIndex);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BACK_BUFFER_IMPL_H
