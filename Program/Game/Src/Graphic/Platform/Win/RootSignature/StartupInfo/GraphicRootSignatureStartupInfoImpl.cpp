#include "GraphicRootSignatureStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	RootSignatureStartupInfoImpl::RootSignatureStartupInfoImpl()
	{
		m_StartupInfo.pParameters = m_RootParameters;
		m_StartupInfo.pStaticSamplers = m_StaticSamplerDescs;
	}

	void RootSignatureStartupInfoImpl::initialize()
	{

	}

	void RootSignatureStartupInfoImpl::setDescriptorRange(const s32 _rootParameterIndex, const ShaderRegisterInfo _shaderRegisterInfo,
		const s32 _numDescriptor, const DESCRIPTOR_RANGE_TYPE _descriptorRangeType)
	{
		m_DescriptorRanges[_rootParameterIndex].NumDescriptors = _numDescriptor;
		m_DescriptorRanges[_rootParameterIndex].BaseShaderRegister = _shaderRegisterInfo.m_ShaderRegister;
		m_DescriptorRanges[_rootParameterIndex].RegisterSpace = _shaderRegisterInfo.m_RegisterSpace;
		m_DescriptorRanges[_rootParameterIndex].RangeType = ConvDescriptorRangeType(_descriptorRangeType);
		m_DescriptorRanges[_rootParameterIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

		m_RootParameters[_rootParameterIndex].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
		m_RootParameters[_rootParameterIndex].ShaderVisibility = ConvShaderVisibilityType(_shaderRegisterInfo.m_ShaderVisibilityType);
		m_RootParameters[_rootParameterIndex].DescriptorTable.NumDescriptorRanges = 1;
		m_RootParameters[_rootParameterIndex].DescriptorTable.pDescriptorRanges = m_DescriptorRanges + _rootParameterIndex;
	}

	void RootSignatureStartupInfoImpl::setRootParameterCount(const s32 _count)
	{
		m_StartupInfo.NumParameters = _count;
	}

	void RootSignatureStartupInfoImpl::setStaticSampler(const s32 _index, const ShaderRegisterInfo _shaderRegisterInfo,
		const FILTER_TYPE _filterType, const TEXTURE_ADDRESS_MODE _textureAddressMode)
	{
		const auto textureAddressMode = ConvTextureAddressMode(_textureAddressMode);
		m_StaticSamplerDescs[_index].Filter = ConvFilterType(_filterType);
		m_StaticSamplerDescs[_index].AddressU = textureAddressMode;
		m_StaticSamplerDescs[_index].AddressV = textureAddressMode;
		m_StaticSamplerDescs[_index].AddressW = textureAddressMode;
		m_StaticSamplerDescs[_index].MipLODBias = 0.0f;
		m_StaticSamplerDescs[_index].MaxAnisotropy = 16;
		m_StaticSamplerDescs[_index].ComparisonFunc = D3D12_COMPARISON_FUNC_LESS_EQUAL;
		m_StaticSamplerDescs[_index].BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE;
		m_StaticSamplerDescs[_index].MinLOD = 0.0f;
		m_StaticSamplerDescs[_index].MaxLOD = D3D12_FLOAT32_MAX;
		m_StaticSamplerDescs[_index].ShaderRegister = _shaderRegisterInfo.m_ShaderRegister;
		m_StaticSamplerDescs[_index].RegisterSpace = _shaderRegisterInfo.m_RegisterSpace;
		m_StaticSamplerDescs[_index].ShaderVisibility = ConvShaderVisibilityType(_shaderRegisterInfo.m_ShaderVisibilityType);
	}

	void RootSignatureStartupInfoImpl::setStaticSamplerCount(const s32 _count)
	{
		m_StartupInfo.NumStaticSamplers = _count;
	}

	void RootSignatureStartupInfoImpl::onRootSignatureFlag(const ROOT_SIGNATURE_FLAG _rootSignatureFlag)
	{
		m_StartupInfo.Flags |= ConvRootSignatureFlag(_rootSignatureFlag);
	}

	void RootSignatureStartupInfoImpl::offRootSignatureFlag(const ROOT_SIGNATURE_FLAG _rootSignatureFlag)
	{
		m_StartupInfo.Flags &= ~ConvRootSignatureFlag(_rootSignatureFlag);
	}
}

CANDY_NAMESPACE_END
