#include "GraphicRootSignatureStartupInfo.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void RootSignatureStartupInfo::initialize()
	{
		RootSignatureStartupInfoImpl::initialize();
	}

	void RootSignatureStartupInfo::setDescriptorRange(const s32 _rootParameterIndex, 
		const ShaderRegisterInfo _shaderRegisterInfo, const Descriptor& _descriptor)
	{
		RootSignatureStartupInfoImpl::setDescriptorRange(_rootParameterIndex, _shaderRegisterInfo, _descriptor);
	}

	void RootSignatureStartupInfo::setRootParameterCount(const s32 _count)
	{
		RootSignatureStartupInfoImpl::setRootParameterCount(_count);
	}

	void RootSignatureStartupInfo::setStaticSampler(const s32 _index, const ShaderRegisterInfo _shaderRegisterInfo, 
		const FILTER_TYPE _filterType, const TEXTURE_ADDRESS_MODE _textureAddressMode)
	{
		RootSignatureStartupInfoImpl::setStaticSampler(_index, _shaderRegisterInfo, _filterType, _textureAddressMode);
	}

	void RootSignatureStartupInfo::setStaticSamplerCount(const s32 _count)
	{
		RootSignatureStartupInfoImpl::setStaticSamplerCount(_count);
	}

	void RootSignatureStartupInfo::onRootSignatureFlag(const ROOT_SIGNATURE_FLAG _rootSignatureFlag)
	{
		RootSignatureStartupInfoImpl::onRootSignatureFlag(_rootSignatureFlag);
	}

	void RootSignatureStartupInfo::offRootSignatureFlag(const ROOT_SIGNATURE_FLAG _rootSignatureFlag)
	{
		RootSignatureStartupInfoImpl::offRootSignatureFlag(_rootSignatureFlag);
	}
}

CANDY_NAMESPACE_END
