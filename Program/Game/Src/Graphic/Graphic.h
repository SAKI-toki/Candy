#ifndef CANDY_GRAPHIC_H
#define CANDY_GRAPHIC_H

#include "GraphicDef.h"
#include "Device/GraphicDevice.h"
#include "Buffer/GraphicBuffer.h"
#include "CommandList/GraphicCommandList.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Startup();
	void Cleanup();
	void Update();
	void PreDraw();
	void PostDraw();

	void RegistBuffer(const Graphic::Buffer& _buffer);

	Device& GetDevice();
	CommandList& GetCommandList();
	s32 GetBackBufferIndex();
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_H
