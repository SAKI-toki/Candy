#include "Graphic.h"
#include "Device/GraphicDevice.h"
#include "CommandQueue/GraphicCommandQueue.h"
#include "CommandList/GraphicCommandList.h"
#include "SwapChain/GraphicSwapChain.h"
#include "Fence/GraphicFence.h"
#include "Buffer/GraphicBuffer.h"
#include "Viewport/GraphicViewport.h"
#include "ScissorRect/GraphicScissorRect.h"
#include "Descriptor/GraphicDescriptor.h"
#include "RootSignature/GraphicRootSignature.h"
#include "Pipeline/GraphicPipeline.h"
#include "BufferView/Vertex/GraphicVertexBufferView.h"
#include "BufferView/Index/GraphicIndexBufferView.h"
#include <Shader/Shader.h>

#include <FileSystem/FileSystem.h>

#if PLATFORM_WIN
#include "Platform/Win/GraphicImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	Viewport m_Viewport;
	ScissorRect m_ScissorRect;
	Device m_Device;
	CommandQueue m_CommandQueue;
	CommandList m_CommandList;
	SwapChain m_SwapChain;
	std::vector<Buffer> m_BackBuffers;
	Descriptor m_BackBufferDescriptor;
	Fence m_FrameFence;
	Descriptor m_Descriptor;
	RootSignature m_RootSignature;
	Pipeline m_Pipeline;
	Buffer m_VertexBuffer;
	Buffer m_IndexBuffer;
	VertexBufferView m_VertexBufferView;
	IndexBufferView m_IndexBufferView;

	s32 m_BackBufferIndex;
	std::vector<u64> m_FrameFenceValues;

	Vec4 m_BackBufferClearColor;
}

void Graphic::Startup()
{
	Shader::Startup();
	m_Device.startup();
	Impl::preCalc(m_Device.getDevice());

	Rect screenRect{ 0.0f, 0.0f, static_cast<f32>(GetScreenWidth()), static_cast<f32>(GetScreenHeight()) };
	m_Viewport.set(screenRect, 0.0f, 1.0f);
	m_ScissorRect.set(screenRect);

	m_CommandQueue.startup(m_Device, COMMAND_LIST_TYPE::RENDERING);
	m_CommandList.startup(m_Device, COMMAND_LIST_TYPE::RENDERING, GetBackBufferCount());
	m_CommandList.close();

	m_SwapChain.startup(m_Device, m_CommandQueue, GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		GetBackBufferCount(), GetScreenWidth(), GetScreenHeight());
	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	m_BackBufferDescriptor.startup(m_Device, DESCRIPTOR_TYPE::RENDER_TARGET, GetBackBufferCount());
	m_BackBuffers.resize(GetBackBufferCount());
	for (s32 i = 0; i < m_BackBuffers.size(); ++i)
	{
		m_BackBuffers[i].startupBackBuffer(m_SwapChain, i);
		m_BackBufferDescriptor.bindingRenderTarget(m_Device, m_BackBuffers[i], i);
	}

	m_FrameFence.startup(m_Device);
	m_FrameFenceValues.resize(GetBackBufferCount());
	m_FrameFenceValues[m_BackBufferIndex] = 1;

	m_Descriptor.startup(m_Device, DESCRIPTOR_TYPE::SHADER_RESOURCE, 1);

	RootSignatureStartupInfo rootSignatureStartupInfo;
	rootSignatureStartupInfo.initialize();
	//rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, SHADER_VISIBILITY_TYPE::PIXEL }, m_Descriptor);
	//rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, SHADER_VISIBILITY_TYPE::PIXEL }, FILTER_TYPE::ANISOTROPIC);
	rootSignatureStartupInfo.setRootParameterCount(0);
	rootSignatureStartupInfo.setStaticSamplerCount(0);
	rootSignatureStartupInfo.onRootSignatureFlag(ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
	m_RootSignature.startup(m_Device, rootSignatureStartupInfo);

	PipelineStartupInfo pipelineStartupInfo;
	pipelineStartupInfo.initialize();
	pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::TEST));
	pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::TEST));
	pipelineStartupInfo.setInputLayoutElement(0, SHADER_SEMANTIC_TYPE::POSITION, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
	pipelineStartupInfo.setInputLayoutCount(1);
	pipelineStartupInfo.setRenderTaretFormat(0, GRAPHIC_FORMAT::R8G8B8A8_UNORM);
	pipelineStartupInfo.setRenderTaretCount(1);
	pipelineStartupInfo.setEnableDepth(false);
	pipelineStartupInfo.setRootSignature(m_RootSignature);
	m_Pipeline.startup(m_Device, pipelineStartupInfo);

	Vec4 vertices[] =
	{
		{ 0.0f, 0.25f, 0.0f },
		{ 0.25f, -0.25f, 0.0f },
		{ -0.25f, -0.25f, 0.0f },
	};
	BufferStartupInfo vertexBufferStartupInfo;
	vertexBufferStartupInfo.setBufferStartupInfo(sizeof(Vec4) * GetArraySize(vertices));
	m_VertexBuffer.startup(m_Device, vertexBufferStartupInfo);
	m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(Vec4) * GetArraySize(vertices), 0);
	m_VertexBufferView.startup(m_VertexBuffer, 0, sizeof(Vec4) * GetArraySize(vertices), sizeof(Vec4));

	u32 indices[] =
	{
		0, 1, 2,
	};
	BufferStartupInfo indexBufferStartupInfo;
	indexBufferStartupInfo.setBufferStartupInfo(sizeof(u32) * GetArraySize(indices));
	m_IndexBuffer.startup(m_Device, indexBufferStartupInfo);
	m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u32) * GetArraySize(indices), 0);
	m_IndexBufferView.startup(m_IndexBuffer, 0, sizeof(Vec4) * GetArraySize(vertices), GRAPHIC_FORMAT::R32_UINT);
}

void Graphic::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);
	m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);

	m_Pipeline.cleanup();
	m_RootSignature.cleanup();
	m_FrameFence.cleanup();
	m_BackBufferDescriptor.cleanup();
	for (auto& backBuffer : m_BackBuffers)backBuffer.cleanup();
	m_BackBuffers.clear();
	m_SwapChain.cleanup();
	m_CommandList.cleanup();
	m_CommandQueue.cleanup();
	m_Device.cleanup();
	Shader::Cleanup();
}

void Graphic::Update()
{
	m_BackBufferClearColor.m_f32Col.r = (std::sin(Global::GetAppTimeAll() * 1) + 1.0f) / 2.0f;
	m_BackBufferClearColor.m_f32Col.g = (std::sin(Global::GetAppTimeAll() * 2) + 1.0f) / 2.0f;
	m_BackBufferClearColor.m_f32Col.b = (std::sin(Global::GetAppTimeAll() * 5) + 1.0f) / 2.0f;
}

void Graphic::DrawBegin()
{
	m_CommandList.drawBegin(m_BackBufferIndex);

	m_CommandList.setViewport(m_Viewport);
	m_CommandList.setScissorRect(m_ScissorRect);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::RENDER_TARGET);

	m_CommandList.setRenderTargets(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), 1);
	m_CommandList.clearRenderTarget(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), m_BackBufferClearColor);

	m_CommandList.setRootSignature(m_RootSignature);
	m_CommandList.setPipeline(m_Pipeline);
}

void Graphic::DrawEnd()
{
	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::PRESENT);

	m_CommandList.close();

	m_CommandQueue.executeCommandList(m_CommandList);

	m_SwapChain.present(1);

	const u64 prevFrameFenceValue = m_FrameFenceValues[m_BackBufferIndex];
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);

	m_BackBufferIndex = m_SwapChain.getBackBufferIndex();

	if (m_FrameFence.getCompletedValue() < m_FrameFenceValues[m_BackBufferIndex])
	{
		m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);
	}
	m_FrameFenceValues[m_BackBufferIndex] = prevFrameFenceValue + 1;

}

CANDY_NAMESPACE_END
