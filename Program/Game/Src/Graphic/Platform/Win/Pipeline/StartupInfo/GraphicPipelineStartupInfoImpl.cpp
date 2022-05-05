#include "GraphicPipelineStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	PipelineStartupInfoImpl::PipelineStartupInfoImpl()
	{
		m_StartupInfo.InputLayout.pInputElementDescs = m_InputElementDescs;
	}

	void PipelineStartupInfoImpl::startup()
	{
		m_StartupInfo.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
		m_StartupInfo.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;
		m_StartupInfo.RasterizerState.FrontCounterClockwise = FALSE;
		m_StartupInfo.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
		m_StartupInfo.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
		m_StartupInfo.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;

		m_StartupInfo.DepthStencilState.DepthEnable = TRUE;
		m_StartupInfo.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
		m_StartupInfo.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;

		m_StartupInfo.SampleDesc.Count = 1;
		m_StartupInfo.SampleMask = UINT_MAX;
		m_StartupInfo.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	}

	void PipelineStartupInfoImpl::setVertexShader(const D3D12_SHADER_BYTECODE& _shader)
	{
		m_StartupInfo.VS = _shader;
	}

	void PipelineStartupInfoImpl::setPixelShader(const D3D12_SHADER_BYTECODE& _shader)
	{
		m_StartupInfo.PS = _shader;
	}

	void PipelineStartupInfoImpl::setRenderTaretFormat(const s32 _index, const GRAPHIC_FORMAT _graphicFormat)
	{
		m_StartupInfo.RTVFormats[_index] = ConvGraphicFormat(_graphicFormat);
	}

	void PipelineStartupInfoImpl::setRenderTaretCount(const s32 _count)
	{
		m_StartupInfo.NumRenderTargets = _count;
	}

	void PipelineStartupInfoImpl::setDepthStencilFormat(const GRAPHIC_FORMAT _graphicFormat)
	{
		m_StartupInfo.DSVFormat = ConvGraphicFormat(_graphicFormat);
	}

	void PipelineStartupInfoImpl::setInputLayoutElement(const s32 _index, const SHADER_SEMANTIC_TYPE _shaderSemanticType,
		const s32 _semanticIndex, const GRAPHIC_FORMAT _graphicFormat)
	{
		m_InputElementDescs[_index].SemanticName = GetShaderSemanticName(_shaderSemanticType);
		m_InputElementDescs[_index].SemanticIndex = _semanticIndex;
		m_InputElementDescs[_index].Format = ConvGraphicFormat(_graphicFormat);
		m_InputElementDescs[_index].InputSlot = 0;
		m_InputElementDescs[_index].AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
		m_InputElementDescs[_index].InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
		m_InputElementDescs[_index].InstanceDataStepRate = 0;
	}

	void PipelineStartupInfoImpl::setInputLayoutCount(const s32 _count)
	{
		m_StartupInfo.InputLayout.NumElements = _count;
	}

	void PipelineStartupInfoImpl::setRootSignature(ID3D12RootSignature* const _rootSignature)
	{
		m_StartupInfo.pRootSignature = _rootSignature;
	}
}

CANDY_NAMESPACE_END
