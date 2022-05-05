#include "GraphicRootSignatureStartupInfo.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void RootSignatureStartupInfo::setDescriptorRange(const s32 _rootParameterIndex, 
		const ShaderRegisterType& _shaderRegisterType, const Descriptor& _descriptor)
	{
		RootSignatureStartupInfoImpl::setDescriptorRange(_rootParameterIndex, _shaderRegisterType, _descriptor);
	}

	void RootSignatureStartupInfo::setRootParameterCount(const s32 _count)
	{
		RootSignatureStartupInfoImpl::setRootParameterCount(_count);
	}

	void RootSignatureStartupInfo::setStaticSampler(const s32 _index, 
		const ShaderRegisterType _shaderRegisterType, const FILTER_TYPE _filterType)
	{
		RootSignatureStartupInfoImpl::setStaticSampler(_index, _shaderRegisterType, _filterType);
	}

	void RootSignatureStartupInfo::setStaticSamplerCount(const s32 _count)
	{
		RootSignatureStartupInfoImpl::setStaticSamplerCount(_count);
	}
}

CANDY_NAMESPACE_END
