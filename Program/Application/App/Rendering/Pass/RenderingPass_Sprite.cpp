/*****************************************************************//**
 * \file   RenderingPass_Sprite.cpp
 * \brief  スプライトレンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#if BUILD_DEBUG

#include "RenderingPass_Sprite.h"
#include <App/Rendering/RenderingParam.h>

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{

	void SpritePass::startup()
	{
		auto& graphicDevice = graphic::System::GetDevice();

		graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
		rootSignatureStartupInfo.initialize();
		rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::ALL }, graphic::Config::GetBackBufferCount(), graphic::types::DESCRIPTOR_RANGE_TYPE::CONSTANT_BUFFER);
		rootSignatureStartupInfo.setDescriptorRange(1, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL }, 1, graphic::types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
		rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL },
			graphic::types::FILTER_TYPE::ANISOTROPIC, graphic::types::TEXTURE_ADDRESS_MODE::CLAMP);
		rootSignatureStartupInfo.setRootParameterCount(2);
		rootSignatureStartupInfo.setStaticSamplerCount(1);
		rootSignatureStartupInfo.onRootSignatureFlag(graphic::types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature.startup(graphicDevice, rootSignatureStartupInfo);

		graphic::PipelineStartupInfo pipelineStartupInfo;
		pipelineStartupInfo.initialize();
		pipelineStartupInfo.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::SPRITE));
		pipelineStartupInfo.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::SPRITE));
		pipelineStartupInfo.setInputLayoutElement(0, graphic::types::SHADER_SEMANTIC_TYPE::POSITION, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(1, graphic::types::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(2, graphic::types::SHADER_SEMANTIC_TYPE::COLOR, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutCount(3);
		pipelineStartupInfo.setDepthStencilFormat(graphic::types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT);
		pipelineStartupInfo.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo.setRenderTaretCount(1);
		pipelineStartupInfo.setEnableDepth(false);
		pipelineStartupInfo.setEnableBlend(0, true);
		pipelineStartupInfo.setRootSignature(m_RootSignature);
		m_Pipeline.startup(graphicDevice, pipelineStartupInfo);
	}

	void SpritePass::cleanup()
	{

	}

	void SpritePass::beginPass(graphic::CommandList& _commandList)
	{
		_commandList.setRenderTargetsDepthStencil(m_RenderTargetBufferDescriptor.getCpuHandle(0), 1, m_DepthStencilBufferDescriptor.getCpuHandle(0));
		_commandList.setViewport(m_Viewport);
		_commandList.setScissorRect(m_ScissorRect);

		_commandList.setRootSignature(m_RootSignature);
		_commandList.setPipeline(m_Pipeline);
	}
}

#endif // BUILD_DEBUG

CANDY_APP_NAMESPACE_END
