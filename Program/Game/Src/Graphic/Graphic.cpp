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
#include <Input/Input.h>
#include <Texture/Texture.h>

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
	Buffer m_ConstantBuffer;
	VertexBufferView m_VertexBufferView;
	IndexBufferView m_IndexBufferView;
	Buffer m_TextureBuffer;
	Descriptor m_TextureDescriptor;

	s32 m_BackBufferIndex;
	std::vector<u64> m_FrameFenceValues;

	struct ConstantInfo
	{
		Vec4 time;
	};
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
		m_BackBufferDescriptor.bindingRenderTarget(m_Device, i, m_BackBuffers[i]);
	}

	m_FrameFence.startup(m_Device);
	m_FrameFenceValues.resize(GetBackBufferCount());
	m_FrameFenceValues[m_BackBufferIndex] = 1;

	m_Descriptor.startup(m_Device, DESCRIPTOR_TYPE::CONSTANT_BUFFER, GetBackBufferCount());
	m_TextureDescriptor.startup(m_Device, DESCRIPTOR_TYPE::SHADER_RESOURCE, 1);

	RootSignatureStartupInfo rootSignatureStartupInfo;
	rootSignatureStartupInfo.initialize();
	rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, SHADER_VISIBILITY_TYPE::ALL }, m_Descriptor);
	rootSignatureStartupInfo.setDescriptorRange(1, { 0, 0, SHADER_VISIBILITY_TYPE::ALL }, m_TextureDescriptor);
	rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, SHADER_VISIBILITY_TYPE::ALL },
		FILTER_TYPE::ANISOTROPIC, TEXTURE_ADDRESS_MODE::CLAMP);
	rootSignatureStartupInfo.setRootParameterCount(2);
	rootSignatureStartupInfo.setStaticSamplerCount(1);
	rootSignatureStartupInfo.onRootSignatureFlag(ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
	m_RootSignature.startup(m_Device, rootSignatureStartupInfo);

	PipelineStartupInfo pipelineStartupInfo;
	pipelineStartupInfo.initialize();
	pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::TEST));
	pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::TEST));
	pipelineStartupInfo.setInputLayoutElement(0, SHADER_SEMANTIC_TYPE::POSITION, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
	pipelineStartupInfo.setInputLayoutElement(1, SHADER_SEMANTIC_TYPE::TEXCOORD, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
	pipelineStartupInfo.setInputLayoutElement(2, SHADER_SEMANTIC_TYPE::COLOR, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
	pipelineStartupInfo.setInputLayoutCount(3);
	pipelineStartupInfo.setRenderTaretFormat(0, GRAPHIC_FORMAT::R8G8B8A8_UNORM);
	pipelineStartupInfo.setRenderTaretCount(1);
	pipelineStartupInfo.setEnableDepth(false);
	pipelineStartupInfo.setRootSignature(m_RootSignature);
	m_Pipeline.startup(m_Device, pipelineStartupInfo);

	Texture::Startup();

	struct VertexInfo
	{
		Vec4 position;
		Vec4 texcoord;
		Color color;
	};	
	VertexInfo vertices[] =
	{
		{ { -0.25f, +0.25f, 0.0f },{ 0.0f, 0.0f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff) }, // ¶ã
		{ { +0.25f, +0.25f, 0.0f },{ 1.0f, 0.0f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff) }, // ‰Eã
		{ { -0.25f, -0.25f, 0.0f },{ 0.0f, 1.0f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff) }, // ¶‰º
		{ { +0.25f, -0.25f, 0.0f },{ 1.0f, 1.0f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff) }, // ‰E‰º
	};
	BufferStartupInfo vertexBufferStartupInfo;
	vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * GetArraySize(vertices));
	m_VertexBuffer.startup(m_Device, vertexBufferStartupInfo);
	m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * GetArraySize(vertices), 0);
	m_VertexBufferView.startup(m_VertexBuffer, 0, GetArraySize(vertices), sizeof(VertexInfo));

	u32 indices[] =
	{
		0, 1, 2,
		1, 3, 2,
	};
	BufferStartupInfo indexBufferStartupInfo;
	indexBufferStartupInfo.setBufferStartupInfo(sizeof(u32) * GetArraySize(indices));
	m_IndexBuffer.startup(m_Device, indexBufferStartupInfo);
	m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u32) * GetArraySize(indices), 0);
	m_IndexBufferView.startup(m_IndexBuffer, 0, GetArraySize(indices), sizeof(u32), GRAPHIC_FORMAT::R32_UINT);

	BufferStartupInfo constantBufferStartupInfo;
	constantBufferStartupInfo.setBufferStartupInfo(0x100 * GetBackBufferCount());
	m_ConstantBuffer.startup(m_Device, constantBufferStartupInfo);
	for (s32 i = 0; i < GetBackBufferCount(); ++i)
	{
		m_Descriptor.bindingConstantBuffer(m_Device, i, m_ConstantBuffer, 0x100 * i, 0x100);
	}

	BufferStartupInfo textureBufferStartupInfo;
	textureBufferStartupInfo.setTextureStartupInfo(GRAPHIC_FORMAT::R32G32B32A32_FLOAT, 256, 256);
	m_TextureBuffer.startup(m_Device, textureBufferStartupInfo);
	m_TextureDescriptor.bindingTexture2D(m_Device, 0, m_TextureBuffer, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);

	Vec4* data = new Vec4[256 * 256];
	for (s32 i = 0; i < 256; ++i)
	{
		for (s32 j = 0; j < 256; ++j)
		{
			data[i * 256 + j] = CANDY_COLOR_RGB32(i, j, 0x00);
		}
	}
	Texture::CreateTexture(m_TextureBuffer, reinterpret_cast<std::byte*>(data), sizeof(Vec4) * 256 * 256);
}

void Graphic::Cleanup()
{
	m_FrameFence.signalFromGpu(m_CommandQueue, m_FrameFenceValues[m_BackBufferIndex]);
	m_FrameFence.waitCpu(m_FrameFenceValues[m_BackBufferIndex]);

	Texture::Cleanup();

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
	static ConstantInfo constantInfo;
	//constantInfo.time = Vec4{ Global::GetAppTimeAll(), Global::GetAppTimeAll(), Global::GetAppTimeAll(), Global::GetAppTimeAll() };
	if (Input::IsKeyOn('A'))
	{
		constantInfo.time.m_f32.w += Global::GetAppTime();
	}
	if (Input::IsKeyOn('D'))
	{
		constantInfo.time.m_f32.w -= Global::GetAppTime();
	}
	m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&constantInfo), sizeof(constantInfo), 0x100 * m_BackBufferIndex);
}

void Graphic::PreDraw()
{
	Texture::ExecuteUploadTexture(m_CommandQueue);

	m_CommandList.preDraw(m_BackBufferIndex);

	m_BackBuffers[m_BackBufferIndex].translationBarrier(m_CommandList, BARRIER_STATE::RENDER_TARGET);

	m_CommandList.setRenderTargets(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), 1);
	m_CommandList.clearRenderTarget(m_BackBufferDescriptor.getCpuHandle(m_BackBufferIndex), CANDY_COLOR_RGB32(0x20, 0x20, 0x20));

	m_CommandList.setViewport(m_Viewport);
	m_CommandList.setScissorRect(m_ScissorRect);

	m_CommandList.setRootSignature(m_RootSignature);
	m_CommandList.setPipeline(m_Pipeline);
	m_CommandList.setVertexBuffers(m_VertexBufferView);
	m_CommandList.setIndexBuffer(m_IndexBufferView);
	m_CommandList.setPrimitiveTopology(PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);

	m_CommandList.setDescriptor(m_Descriptor);
	m_CommandList.setDescriptorTable(0, m_Descriptor, m_BackBufferIndex);
	m_CommandList.setDescriptor(m_TextureDescriptor);
	m_CommandList.setDescriptorTable(1, m_TextureDescriptor, 0);

	m_CommandList.drawIndexedInstanced(m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);
}

void Graphic::PostDraw()
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

	Texture::PostDraw();
}

Graphic::Device& Graphic::GetDevice()
{
	return m_Device;
}

s32 Graphic::GetBackBufferIndex()
{
	return m_BackBufferIndex;
}

CANDY_NAMESPACE_END
