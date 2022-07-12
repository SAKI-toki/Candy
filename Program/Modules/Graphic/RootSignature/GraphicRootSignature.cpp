#include "GraphicRootSignature.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void RootSignature::startup(const Device& _device, const RootSignatureStartupInfo& _startupInfo)
{
	RootSignatureImpl::startup(_device.getDevice(), _startupInfo.getStartupInfo());
}

void RootSignature::cleanup()
{
	RootSignatureImpl::cleanup();
}

CANDY_GRAPHIC_NAMESPACE_END
