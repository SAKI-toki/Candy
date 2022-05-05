#include "GraphicPipeline.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Pipeline::startup(const Device& _device, const PipelineStartupInfo& _startupInfo)
	{
		PipelineImpl::startup(_device.getDevice(), _startupInfo.getStartupInfo());
	}

	void Pipeline::cleanup()
	{

	}
}

CANDY_NAMESPACE_END
