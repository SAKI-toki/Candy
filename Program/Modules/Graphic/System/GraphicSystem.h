#ifndef CANDY_GRAPHIC_SYSTEM_H
#define CANDY_GRAPHIC_SYSTEM_H

#include <Graphic/GraphicInclude.h>

#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/CommandList/GraphicCommandList.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace System
{
	void Startup();
	void Cleanup();
	void Update();
	void PreDraw();
	void PostDraw();
	void Flip();

	Device& GetDevice();
	CommandList& GetCommandList();
	Descriptor& GetBackBufferDescriptor();
	s32 GetBackBufferIndex();
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SYSTEM_H
