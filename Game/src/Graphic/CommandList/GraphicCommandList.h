#ifndef CANDY_GRAPHIC_COMMAND_LIST_H
#define CANDY_GRAPHIC_COMMAND_LIST_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>
#include <Graphic/Descriptor/Handle/CPU/GraphicDescriptorCpuHandle.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/CommandList/GraphicCommandListImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class CommandList : public CommandListImpl
	{
	public:
		void startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount);
		void cleanup();

		void drawBegin(const s32 _backBufferIndex);

		void close();

		void setViewport(const Viewport& _viewport);
		void setScissorRect(const ScissorRect& _scissorRect);

		void setRenderTargets(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const s32 _renderTargetCount);
		void setRenderTargetsDepthStencil(const DescriptorCpuHandle& _rtDescriptorCpuHandle,
			const s32 _renderTargetCount, const DescriptorCpuHandle& _dsDescriptorCpuHandle);
		void clearRenderTarget(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const Vec4 _color);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_H
