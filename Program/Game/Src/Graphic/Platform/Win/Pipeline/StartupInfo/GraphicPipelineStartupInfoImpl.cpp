#include "GraphicPipelineStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	PipelineStartupInfoImpl::PipelineStartupInfoImpl()
	{
		m_StartupInfo.InputLayout.pInputElementDescs = m_InputElementDescs;
	}

	void PipelineStartupInfoImpl::initialize()
	{
		m_StartupInfo.BlendState.AlphaToCoverageEnable = FALSE;
		m_StartupInfo.BlendState.IndependentBlendEnable = FALSE;
		for (int i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
		{
			m_StartupInfo.BlendState.RenderTarget[i].BlendEnable = FALSE;
			m_StartupInfo.BlendState.RenderTarget[i].LogicOpEnable = FALSE;
			m_StartupInfo.BlendState.RenderTarget[i].SrcBlend = D3D12_BLEND_SRC_ALPHA;
			m_StartupInfo.BlendState.RenderTarget[i].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;
			m_StartupInfo.BlendState.RenderTarget[i].BlendOp = D3D12_BLEND_OP_ADD;
			m_StartupInfo.BlendState.RenderTarget[i].SrcBlendAlpha = D3D12_BLEND_ONE;
			m_StartupInfo.BlendState.RenderTarget[i].DestBlendAlpha = D3D12_BLEND_ZERO;
			m_StartupInfo.BlendState.RenderTarget[i].BlendOpAlpha = D3D12_BLEND_OP_ADD;
			m_StartupInfo.BlendState.RenderTarget[i].LogicOp = D3D12_LOGIC_OP_NOOP;
			m_StartupInfo.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
		}

		m_StartupInfo.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
		m_StartupInfo.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;
		m_StartupInfo.RasterizerState.FrontCounterClockwise = FALSE;
		m_StartupInfo.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
		m_StartupInfo.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
		m_StartupInfo.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;

		m_StartupInfo.DepthStencilState.DepthEnable = TRUE;
		m_StartupInfo.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
		m_StartupInfo.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
		m_StartupInfo.DepthStencilState.StencilEnable = FALSE;
		m_StartupInfo.DepthStencilState.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;
		m_StartupInfo.DepthStencilState.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;
		m_StartupInfo.DepthStencilState.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
		m_StartupInfo.DepthStencilState.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
		m_StartupInfo.DepthStencilState.FrontFace.StencilPassOp = D3D12_STENCIL_OP_REPLACE;
		m_StartupInfo.DepthStencilState.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;
		m_StartupInfo.DepthStencilState.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
		m_StartupInfo.DepthStencilState.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
		m_StartupInfo.DepthStencilState.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
		m_StartupInfo.DepthStencilState.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;

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

	void PipelineStartupInfoImpl::setEnableDepth(const bool _isEnableDepth)
	{
		m_StartupInfo.DepthStencilState.DepthEnable = _isEnableDepth;
	}

	void PipelineStartupInfoImpl::setEnableStencil(const bool _isEnableStencil)
	{
		m_StartupInfo.DepthStencilState.StencilEnable = _isEnableStencil;
	}

	void PipelineStartupInfoImpl::setEnableBlend(const s32 _renderTargetIndex, const bool _isEnableBlend)
	{
		m_StartupInfo.BlendState.RenderTarget[_renderTargetIndex].BlendEnable = _isEnableBlend;
	}

	void PipelineStartupInfoImpl::setFillMode(const FILL_MODE _fillMode)
	{
		m_StartupInfo.RasterizerState.FillMode = ConvFillMode(_fillMode);
	}

	void PipelineStartupInfoImpl::setRootSignature(ID3D12RootSignature* const _rootSignature)
	{
		m_StartupInfo.pRootSignature = _rootSignature;
	}
}

CANDY_NAMESPACE_END
