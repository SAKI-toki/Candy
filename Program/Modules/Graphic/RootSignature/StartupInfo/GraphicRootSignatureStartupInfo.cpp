﻿#include "GraphicRootSignatureStartupInfo.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void RootSignatureStartupInfo::initialize()
{
	RootSignatureStartupInfoImpl::initialize();
}

void RootSignatureStartupInfo::setDescriptorRange(const s32 _rootParameterIndex, const types::ShaderRegisterInfo _shaderRegisterInfo,
	const s32 _numDescriptor, const types::DESCRIPTOR_RANGE_TYPE _descriptorRangeType)
{
	RootSignatureStartupInfoImpl::setDescriptorRange(_rootParameterIndex, _shaderRegisterInfo, _numDescriptor, _descriptorRangeType);
}

void RootSignatureStartupInfo::setRootParameterCount(const s32 _count)
{
	RootSignatureStartupInfoImpl::setRootParameterCount(_count);
}

void RootSignatureStartupInfo::setStaticSampler(const s32 _index, const types::ShaderRegisterInfo _shaderRegisterInfo,
	const types::FILTER_TYPE _filterType, const types::TEXTURE_ADDRESS_MODE _textureAddressMode)
{
	RootSignatureStartupInfoImpl::setStaticSampler(_index, _shaderRegisterInfo, _filterType, _textureAddressMode);
}

void RootSignatureStartupInfo::setStaticSamplerCount(const s32 _count)
{
	RootSignatureStartupInfoImpl::setStaticSamplerCount(_count);
}

void RootSignatureStartupInfo::onRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag)
{
	RootSignatureStartupInfoImpl::onRootSignatureFlag(_rootSignatureFlag);
}

void RootSignatureStartupInfo::offRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag)
{
	RootSignatureStartupInfoImpl::offRootSignatureFlag(_rootSignatureFlag);
}

CANDY_GRAPHIC_NAMESPACE_END
