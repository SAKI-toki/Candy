#include "GraphicPipeline.h"
#include <Graphic/Device/GraphicDevice.h>
#include "StartupInfo/GraphicPipelineStartupInfo.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void Pipeline::startup(const Device& _device, const PipelineStartupInfo& _startupInfo)
{
	PipelineImpl::startup(_device.getDevice(), _startupInfo.getStartupInfo());
}

void Pipeline::cleanup()
{

}

CANDY_GRAPHIC_NAMESPACE_END
