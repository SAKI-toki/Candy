#ifndef CANDY_GRAPHIC_H
#define CANDY_GRAPHIC_H

#include "GraphicDef.h"
#include "Device/GraphicDevice.h"
#include "Buffer/GraphicBuffer.h"
#include "RootSignature/GraphicRootSignature.h"
#include "Pipeline/GraphicPipeline.h"
#include "CommandList/GraphicCommandList.h"
#include "Descriptor/GraphicDescriptor.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
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

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_H
