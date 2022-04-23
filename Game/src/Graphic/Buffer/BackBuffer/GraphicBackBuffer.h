#ifndef CANDY_GRAPHIC_BACK_BUFFER_H
#define CANDY_GRAPHIC_BACK_BUFFER_H

#include <Graphic/GraphicDef.h>
#include <Graphic/SwapChain/GraphicSwapChain.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/BackBuffer/GraphicBackBufferImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class BackBuffer : public BackBufferImpl
	{
	public:
		void startup(const SwapChain& _swapChain, const s32 _backBufferIndex);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BACK_BUFFER_H
