#ifndef CANDY_GRAPHIC_BUFFER_H
#define CANDY_GRAPHIC_BUFFER_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/SwapChain/GraphicSwapChain.h>
#include <Graphic/CommandList/GraphicCommandList.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Buffer : public BufferImpl
	{
	public:
		void startupRenderTarget(const Device& _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height);
		void startupBackBuffer(const SwapChain& _swapChain, const s32 _backBufferIndex);
		void cleanup();

		void translationBarrier(const CommandList& _commandList, const BARRIER_STATE _barrierState);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_H
