#include "GraphicRootSignature.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void RootSignature::startup(const Device& _device, const RootSignatureStartupInfo& _startupInfo)
	{
		RootSignatureImpl::startup(_device.getDevice(), _startupInfo.getStartupInfo());
	}

	void RootSignature::cleanup()
	{
		RootSignatureImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
