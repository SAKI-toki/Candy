#ifndef CANDY_GRAPHIC_PIPELINE_H
#define CANDY_GRAPHIC_PIPELINE_H

#include <Graphic/GraphicInclude.h>

#include "StartupInfo/GraphicPipelineStartupInfo.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Pipeline/GraphicPipelineImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device;

class Pipeline : public impl::PipelineImpl
{
public:
	void startup(const Device& _device, const PipelineStartupInfo& _startupInfo);
	void cleanup();
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_H
