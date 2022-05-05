#include "GraphicRootSignatureStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	RootSignatureStartupInfoImpl::RootSignatureStartupInfoImpl()
	{
		m_StartupInfo.pParameters = m_RootParameters;
		m_StartupInfo.pStaticSamplers = m_StaticSamplerDescs;
	}

	void RootSignatureStartupInfoImpl::setDescriptorRange(const s32 _rootParameterIndex,
		const ShaderRegisterType& _shaderRegisterType, const DescriptorImpl& _descriptor)
	{
		m_DescriptorRanges[_rootParameterIndex].NumDescriptors = _descriptor.getDescriptorCount();
		m_DescriptorRanges[_rootParameterIndex].BaseShaderRegister = _shaderRegisterType.m_ShaderRegister;
		m_DescriptorRanges[_rootParameterIndex].RegisterSpace = _shaderRegisterType.m_RegisterSpace;
		m_DescriptorRanges[_rootParameterIndex].RangeType = ConvDescriptorRangeType(_descriptor.getDescriptorType());
		m_DescriptorRanges[_rootParameterIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
		
		m_RootParameters[_rootParameterIndex].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
		m_RootParameters[_rootParameterIndex].ShaderVisibility = ConvShaderVisibilityType(_shaderRegisterType.m_ShaderVisibilityType);
		m_RootParameters[_rootParameterIndex].DescriptorTable.NumDescriptorRanges = 1;
		m_RootParameters[_rootParameterIndex].DescriptorTable.pDescriptorRanges = m_DescriptorRanges + _rootParameterIndex;
	}

	void RootSignatureStartupInfoImpl::setRootParameterCount(const s32 _count)
	{
		m_StartupInfo.NumParameters = _count;
	}

	void RootSignatureStartupInfoImpl::setStaticSampler(const s32 _index,
		const ShaderRegisterType _shaderRegisterType, const FILTER_TYPE _filterType)
	{
		m_StaticSamplerDescs[_index].Filter = ConvFilterType(_filterType);
		m_StaticSamplerDescs[_index].AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		m_StaticSamplerDescs[_index].AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		m_StaticSamplerDescs[_index].AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		m_StaticSamplerDescs[_index].MipLODBias = 0.0f;
		m_StaticSamplerDescs[_index].MaxAnisotropy = 16;
		m_StaticSamplerDescs[_index].ComparisonFunc = D3D12_COMPARISON_FUNC_LESS_EQUAL;
		m_StaticSamplerDescs[_index].BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE;
		m_StaticSamplerDescs[_index].MinLOD = 0.0f;
		m_StaticSamplerDescs[_index].MaxLOD = D3D12_FLOAT32_MAX;
		m_StaticSamplerDescs[_index].ShaderRegister = _shaderRegisterType.m_ShaderRegister;
		m_StaticSamplerDescs[_index].RegisterSpace = _shaderRegisterType.m_RegisterSpace;
		m_StaticSamplerDescs[_index].ShaderVisibility = ConvShaderVisibilityType(_shaderRegisterType.m_ShaderVisibilityType);
	}

	void RootSignatureStartupInfoImpl::setStaticSamplerCount(const s32 _count)
	{
		m_StartupInfo.NumStaticSamplers = _count;
	}
}

CANDY_NAMESPACE_END
