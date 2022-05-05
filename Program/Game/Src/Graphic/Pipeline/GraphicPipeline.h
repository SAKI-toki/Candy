#ifndef CANDY_GRAPHIC_PIPELINE_H
#define CANDY_GRAPHIC_PIPELINE_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include "StartupInfo/GraphicPipelineStartupInfo.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Pipeline/GraphicPipelineImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Pipeline : public PipelineImpl
	{
	public:
		void startup(const Device& _device, const PipelineStartupInfo& _startupInfo);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_H
