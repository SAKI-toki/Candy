/*****************************************************************//**
 * \file   RenderingPass_EndFrame.cpp
 * \brief  フレーム終了レンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "RenderingPass_EndFrame.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	void EndFramePass::startup()
	{
		auto& graphicDevice = graphic::System::GetDevice();

		m_Descriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, 1);
		m_Descriptor.bindingTexture2D(graphic::System::GetDevice(), 0, m_RenderTargetBuffer, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);

		graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
		rootSignatureStartupInfo.initialize();
		rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL }, 1, graphic::types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
		rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL },
			graphic::types::FILTER_TYPE::ANISOTROPIC, graphic::types::TEXTURE_ADDRESS_MODE::CLAMP);
		rootSignatureStartupInfo.setRootParameterCount(1);
		rootSignatureStartupInfo.setStaticSamplerCount(1);
		rootSignatureStartupInfo.onRootSignatureFlag(graphic::types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature.startup(graphicDevice, rootSignatureStartupInfo);

		graphic::PipelineStartupInfo pipelineStartupInfo;
		pipelineStartupInfo.initialize();
		pipelineStartupInfo.setRootSignature(m_RootSignature);
		pipelineStartupInfo.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::TO_BACK_BUFFER));
		pipelineStartupInfo.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::TO_BACK_BUFFER));
		pipelineStartupInfo.setRenderTaretCount(1);
		pipelineStartupInfo.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo.setEnableDepth(false);
		pipelineStartupInfo.setEnableStencil(false);
		pipelineStartupInfo.setEnableBlend(0, false);
		pipelineStartupInfo.setInputLayoutElement(0, graphic::types::SHADER_SEMANTIC_TYPE::POSITION, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(1, graphic::types::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutCount(2);
		m_Pipeline.startup(graphicDevice, pipelineStartupInfo);

		graphic::BufferStartupInfo vertexBufferStartupInfo;
		struct VertexInfo
		{
			Vec4 pos, texcoord;
		};
		vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * 4);
		m_VertexBuffer.startup(graphicDevice, vertexBufferStartupInfo);
		VertexInfo vertices[4] =
		{
			{ Vec4{ -1.0f, +1.0f, 0.0f }, Vec4{ 0.0f, 0.0f, 0.0f } },
			{ Vec4{ +1.0f, +1.0f, 0.0f }, Vec4{ 1.0f, 0.0f, 0.0f } },
			{ Vec4{ +1.0f, -1.0f, 0.0f }, Vec4{ 1.0f, 1.0f, 0.0f } },
			{ Vec4{ -1.0f, -1.0f, 0.0f }, Vec4{ 0.0f, 1.0f, 0.0f } },
		};
		m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * 4, 0);

		graphic::BufferStartupInfo indexBufferStartupInfo;
		indexBufferStartupInfo.setBufferStartupInfo(sizeof(u16) * 6);
		m_IndexBuffer.startup(graphicDevice, indexBufferStartupInfo);
		u16 indices[6] = { 0, 1, 2, 0, 2, 3 };
		m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u16) * 6, 0);

		m_VertexBufferView.startup(m_VertexBuffer, 0, 4, sizeof(VertexInfo));
		m_IndexBufferView.startup(m_IndexBuffer, 0, 6, sizeof(u16), graphic::types::GRAPHIC_FORMAT::R16_UINT);
	}

	void EndFramePass::cleanup()
	{
		m_Pipeline.cleanup();
		m_VertexBuffer.cleanup();
		m_IndexBuffer.cleanup();
	}

	void EndFramePass::beginPass(graphic::CommandList& _commandList)
	{
		auto& currentBackBuffer = graphic::System::GetCurrentBackBuffer();
		auto currentBackBufferDescriptorCpuHandle = graphic::System::GetBackBufferDescriptorCpuHandle();
		_commandList.translationBufferBarrier(m_RenderTargetBuffer, graphic::types::BARRIER_STATE::RENDER_TARGET, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
		_commandList.translationBufferBarrier(currentBackBuffer, graphic::types::BARRIER_STATE::PRESENT, graphic::types::BARRIER_STATE::RENDER_TARGET);
		_commandList.setRenderTargets(currentBackBufferDescriptorCpuHandle, 1);
		_commandList.setViewport(m_Viewport);
		_commandList.setScissorRect(m_ScissorRect);
		_commandList.setRootSignature(m_RootSignature);
		_commandList.setPipeline(m_Pipeline);
		_commandList.setDescriptor(0, m_Descriptor);
		_commandList.registDescriptors(1, 0);
		_commandList.setDescriptorTable(0, m_Descriptor, 0);
		_commandList.setVertexBuffer(0, m_VertexBufferView);
		_commandList.registVertexBuffers(1);
		_commandList.setIndexBuffer(m_IndexBufferView);
		_commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		_commandList.drawIndexedInstanced(m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);
		_commandList.translationBufferBarrier(currentBackBuffer, graphic::types::BARRIER_STATE::RENDER_TARGET, graphic::types::BARRIER_STATE::PRESENT);

		graphic::ResourceLifetime::Regist(m_VertexBuffer);
		graphic::ResourceLifetime::Regist(m_IndexBuffer);
	}
}

CANDY_APP_NAMESPACE_END
