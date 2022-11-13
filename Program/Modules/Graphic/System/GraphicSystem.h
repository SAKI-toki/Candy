#ifndef CANDY_GRAPHIC_SYSTEM_H
#define CANDY_GRAPHIC_SYSTEM_H

#include <Graphic/GraphicInclude.h>

#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/Fence/GraphicFence.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace System
{
	void Startup();
	void Cleanup();
	void Update();
	void BeginDraw();
	void Flip();

	void ExecuteCommandList(CommandList& _commandList);

	Device& GetDevice();
	Buffer& GetCurrentBackBuffer();
	Descriptor& GetBackBufferDescriptor();
	DescriptorCpuHandle GetBackBufferDescriptorCpuHandle();
	const Viewport& GetBackBufferViewport();
	const ScissorRect& GetBackBufferScissorRect();
	s32 GetBackBufferIndex();
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SYSTEM_H
