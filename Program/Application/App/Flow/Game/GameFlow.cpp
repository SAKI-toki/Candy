/*****************************************************************//**
 * \file   GameFlow.cpp
 * \brief  ゲームフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "GameFlow.h"
#include <App/Flow/Scene/SceneFlow.h>
#include <App/Model/Model.h>
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

namespace GameFlow
{
	graphic::Buffer m_MaskBuffer;
	graphic::Descriptor m_MaskDescriptor;

	class TextureView
	{
	public:
		u32 flag = 0;
		struct VertexInfo
		{
			Vec4 position;
			Vec4 texcoord;
			Color color;
		};
		enum STARTUP_FLAG
		{
			STARTUP_FLAG_NONE = 0,
			STARTUP_FLAG_USE_ALPHA = (1 << 0),
			STARTUP_FLAG_WRITE_MASK = (1 << 1),
		};
		void startup(const std::string& _texturePath, const u32 _width, const u32 _height, const Vec4 _scale, const u32 _startupFlag)
		{
			flag = _startupFlag;
			m_Descriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, graphic::Config::GetBackBufferCount() + 2);

			graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
			rootSignatureStartupInfo.initialize();
			rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::ALL }, graphic::Config::GetBackBufferCount(), graphic::types::DESCRIPTOR_RANGE_TYPE::CONSTANT_BUFFER);
			rootSignatureStartupInfo.setDescriptorRange(1, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL }, 1, graphic::types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
			rootSignatureStartupInfo.setDescriptorRange(2, { 1, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL }, 1, graphic::types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
			rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL },
				graphic::types::FILTER_TYPE::ANISOTROPIC, graphic::types::TEXTURE_ADDRESS_MODE::CLAMP);
			rootSignatureStartupInfo.setRootParameterCount(3);
			if (_startupFlag & STARTUP_FLAG_WRITE_MASK)
			{
				rootSignatureStartupInfo.setRootParameterCount(2);
			}
			rootSignatureStartupInfo.setStaticSamplerCount(1);
			rootSignatureStartupInfo.onRootSignatureFlag(graphic::types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
			m_RootSignature.startup(graphic::System::GetDevice(), rootSignatureStartupInfo);

			graphic::PipelineStartupInfo pipelineStartupInfo;
			pipelineStartupInfo.initialize();
			pipelineStartupInfo.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::TEST));
			pipelineStartupInfo.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::TEST));
			pipelineStartupInfo.setInputLayoutElement(0, graphic::types::SHADER_SEMANTIC_TYPE::POSITION, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(1, graphic::types::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(2, graphic::types::SHADER_SEMANTIC_TYPE::COLOR, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutCount(3);
			pipelineStartupInfo.setDepthStencilFormat(graphic::types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT);
			pipelineStartupInfo.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
			if (_startupFlag & STARTUP_FLAG_WRITE_MASK)
			{
				pipelineStartupInfo.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::A8_UINT);
				pipelineStartupInfo.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::TEST_MASK));
				pipelineStartupInfo.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::TEST_MASK));
			}
			pipelineStartupInfo.setRenderTaretCount(1);
			pipelineStartupInfo.setEnableDepth(false);
			pipelineStartupInfo.setEnableBlend(0, true);
			pipelineStartupInfo.setRootSignature(m_RootSignature);
			m_Pipeline.startup(graphic::System::GetDevice(), pipelineStartupInfo);

			VertexInfo vertices[] =
			{
				{ Vec4{ -0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 0.0f, 0.0f }, core::GetColorRGBA32(0xff, 0xff, 0xff, 0xff) }, // 左上
				{ Vec4{ +0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 0.0f, 0.0f }, core::GetColorRGBA32(0xff, 0xff, 0xff, 0xff) }, // 右上
				{ Vec4{ -0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 1.0f, 0.0f }, core::GetColorRGBA32(0xff, 0xff, 0xff, 0xff) }, // 左下
				{ Vec4{ +0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 1.0f, 0.0f }, core::GetColorRGBA32(0xff, 0xff, 0xff, 0xff) }, // 右下
			};
			graphic::BufferStartupInfo vertexBufferStartupInfo;
			vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * core::GetArraySize(vertices));
			m_VertexBuffer.startup(graphic::System::GetDevice(), vertexBufferStartupInfo);
			m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * core::GetArraySize(vertices), 0);

			u32 indices[] =
			{
				0, 1, 2,
				1, 3, 2,
			};
			graphic::BufferStartupInfo indexBufferStartupInfo;
			indexBufferStartupInfo.setBufferStartupInfo(sizeof(u32) * core::GetArraySize(indices));
			m_IndexBuffer.startup(graphic::System::GetDevice(), indexBufferStartupInfo);
			m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u32) * core::GetArraySize(indices), 0);

			graphic::BufferStartupInfo constantBufferStartupInfo;
			constantBufferStartupInfo.setBufferStartupInfo(0x100 * graphic::Config::GetBackBufferCount());
			m_ConstantBuffer.startup(graphic::System::GetDevice(), constantBufferStartupInfo);
			for (s32 i = 0; i < graphic::Config::GetBackBufferCount(); ++i)
			{
				m_Descriptor.bindingConstantBuffer(graphic::System::GetDevice(), i, m_ConstantBuffer, 0x100 * i, 0x100);
			}

			graphic::types::GRAPHIC_FORMAT format = (_startupFlag & STARTUP_FLAG_USE_ALPHA) ? graphic::types::GRAPHIC_FORMAT::BC3_UNORM : graphic::types::GRAPHIC_FORMAT::BC1_UNORM;
			graphic::BufferStartupInfo textureBufferStartupInfo;
			textureBufferStartupInfo.setTextureStartupInfo(format, _width, _height);
			m_TextureBuffer.startup(graphic::System::GetDevice(), textureBufferStartupInfo);
			m_Descriptor.bindingTexture2D(graphic::System::GetDevice(), graphic::Config::GetBackBufferCount() + 0, m_TextureBuffer, format);
			m_Descriptor.bindingTexture2D(graphic::System::GetDevice(), graphic::Config::GetBackBufferCount() + 1, m_MaskBuffer, graphic::types::GRAPHIC_FORMAT::A8_UINT);

			auto path = std::string{ core::Config::GetDataPath() } + _texturePath;
			u64 size = core::FileSystem::GetFileSize(path);
			std::byte* buf = new std::byte[size];
			core::FileSystem::RequestReadNoWait(path, buf, size);
			auto result = graphic::Texture::DDS::ReadAlloc(buf, size);
			graphic::TextureManager::CreateTexture(m_TextureBuffer, result, _width * _height / ((_startupFlag & STARTUP_FLAG_USE_ALPHA) ? 1 : 2));
		}
		void cleanup()
		{
			m_Descriptor.cleanup();
			m_RootSignature.cleanup();
			m_Pipeline.cleanup();
			m_VertexBuffer.cleanup();
			m_IndexBuffer.cleanup();
			m_ConstantBuffer.cleanup();
			m_TextureBuffer.cleanup();
		}
		void update()
		{
			m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&m_Constant), sizeof(m_Constant), 0x100 * graphic::System::GetBackBufferIndex());
		}
		void draw()
		{
			auto& commandList = graphic::System::GetCommandList();

			if(flag & STARTUP_FLAG_WRITE_MASK)
			{
				m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::RENDER_TARGET);
				commandList.setRenderTargets(m_MaskDescriptor.getCpuHandle(0), 1);
			}

			commandList.setRootSignature(m_RootSignature);
			commandList.setPipeline(m_Pipeline);

			m_TextureBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

			commandList.setDescriptor(0, m_Descriptor);
			commandList.registDescriptors(1, 0);
			commandList.setDescriptorTable(0, m_Descriptor, graphic::System::GetBackBufferIndex());
			commandList.setDescriptorTable(1, m_Descriptor, graphic::Config::GetBackBufferCount() + 0);
			if (!(flag & STARTUP_FLAG_WRITE_MASK))
			{
				commandList.setDescriptorTable(2, m_Descriptor, graphic::Config::GetBackBufferCount() + 1);
			}

			graphic::VertexBufferView vertexBufferView;
			vertexBufferView.startup(m_VertexBuffer, 0, 4, sizeof(VertexInfo));
			graphic::IndexBufferView indexBufferView;
			indexBufferView.startup(m_IndexBuffer, 0, 6, sizeof(u32), graphic::types::GRAPHIC_FORMAT::R32_UINT);
			commandList.setVertexBuffer(0, vertexBufferView);
			commandList.registVertexBuffers(1);
			commandList.setIndexBuffer(indexBufferView);
			commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
			commandList.drawIndexedInstanced(indexBufferView.getIndexCount(), 1, 0, 0, 0);

			if (flag & STARTUP_FLAG_WRITE_MASK)
			{
				m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
				commandList.setRenderTargets(graphic::System::GetBackBufferDescriptor().getCpuHandle(graphic::System::GetBackBufferIndex()), 1);
			}

			graphic::ResourceManager::Regist(m_VertexBuffer);
			graphic::ResourceManager::Regist(m_IndexBuffer);
			graphic::ResourceManager::Regist(m_ConstantBuffer);
			graphic::ResourceManager::Regist(m_TextureBuffer);
		}

		struct Constant
		{
			Vec4 m_Position{};
			Color m_Color{ core::GetColorRGB32(0xff, 0xff, 0xff) };
			Vec4 pad[14];
		}m_Constant;
	private:
		graphic::Descriptor m_Descriptor;
		graphic::RootSignature m_RootSignature;
		graphic::Pipeline m_Pipeline;
		graphic::Buffer m_VertexBuffer;
		graphic::Buffer m_IndexBuffer;
		graphic::Buffer m_ConstantBuffer;
		graphic::Buffer m_TextureBuffer;
	};

	TextureView m_TextureViews[4];
}

// 初期化
void GameFlow::Startup()
{
	core::Input::Startup();

	graphic::BufferStartupInfo bufferStartupInfo;
	bufferStartupInfo.setRenderTargetStartupInfo(graphic::types::GRAPHIC_FORMAT::A8_UINT, graphic::Config::GetScreenWidth(), graphic::Config::GetScreenHeight());
	m_MaskDescriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::RENDER_TARGET, 1);
	m_MaskBuffer.startup(graphic::System::GetDevice(), bufferStartupInfo);
	m_MaskDescriptor.bindingRenderTarget(graphic::System::GetDevice(), 0, m_MaskBuffer, graphic::types::GRAPHIC_FORMAT::A8_UINT);

	m_TextureViews[0].startup(R"(Texture\forest.dds)", 512, 256, Vec4{ 8.0f * 9 / 16, 4.0f * 9 / 16, 1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[1].startup(R"(Texture\house.dds)", 256, 256, Vec4{ 2.0f,2.0f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[2].startup(R"(Texture\player1.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_USE_ALPHA);
	m_TextureViews[3].startup(R"(Texture\player2.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[2].m_Constant.m_Position.y = -0.65f;
	m_TextureViews[3].m_Constant.m_Position.y = -0.65f;

	//Sound::CallSe("TestBgm.wav", Sound::CALL_SE_FLAG_LOOP);
}

// 破棄
void GameFlow::Cleanup()
{
	for (auto& textureView : m_TextureViews)textureView.cleanup();
	core::Input::Cleanup();
}

// 更新
void GameFlow::Update()
{
	core::Input::Update();

	DebugDraw::DrawString(Vec4{ 100, 100, 0 }, "PlayerPos[x:%.2f y:%.2f]", m_TextureViews[2].m_Constant.m_Position.x, m_TextureViews[2].m_Constant.m_Position.y);
	DebugDraw::DrawString(Vec4{ 100, 120, 0 }, "test");
	DebugDraw::DrawString(Vec4{ 100, 140, 0 }, "AABBあいうえお");

	if (core::Input::IsKeyTrigger('P'))
	{
		CANDY_LOG("PPPP");
	}
	if (core::Input::IsKeyTrigger('O'))
	{
		CANDY_LOG_ERR("OOOO");
	}
	if (core::Input::IsKeyTrigger('I'))
	{
		CANDY_LOG_WARN("IIII");
	}

	constexpr f32 speed = 0.3f;
	static bool isLanding = true;
	static bool isSideVelocity = false;
	static f32 velocity = 0.0f;
	static f32 sideVelocity = 0.0f;
	if (core::Input::IsKeyTrigger('A'))
	{
		sideVelocity -= 4.0f;
		isSideVelocity = true;
	}
	if (core::Input::IsKeyTrigger('D'))
	{
		sideVelocity += 4.0f;
		isSideVelocity = true;
	}
	if (core::Input::IsKeyTrigger('W'))
	{
		if (isLanding)velocity = 4.0f;
		isLanding = false;
	}
	if (!isLanding)
	{
		m_TextureViews[2].m_Constant.m_Position.y += velocity * Global::GetAppTime();
		velocity -= 9.8f * Global::GetAppTime();
	}

	if (isSideVelocity)
	{
		m_TextureViews[2].m_Constant.m_Position.x += sideVelocity * Global::GetAppTime();
		auto prevSideVelocity = sideVelocity;
		sideVelocity -= 9.8f * Global::GetAppTime() * (sideVelocity > 0.0f ? 1.0f : -1.0f);
		if (prevSideVelocity > 0.0f && sideVelocity <= 0.0f ||
			prevSideVelocity < 0.0f && sideVelocity >= 0.0f)
		{
			sideVelocity = 0.0f;
			isSideVelocity = false;
		}
	}
	if (m_TextureViews[2].m_Constant.m_Position.y <= -0.65f)
	{
		m_TextureViews[2].m_Constant.m_Position.y = -0.65f;
		velocity = 0.0f;
		isLanding = true;
	}
	if (m_TextureViews[2].m_Constant.m_Position.x > 0.7f ||
		m_TextureViews[2].m_Constant.m_Position.x < -0.8f)
	{
		m_TextureViews[2].m_Constant.m_Position.x = core::Clamp(m_TextureViews[2].m_Constant.m_Position.x, -0.8f, 0.7f);
		sideVelocity = 0.0f;
		isSideVelocity = true;
	}

	if (core::Input::IsKeyOn('J'))m_TextureViews[3].m_Constant.m_Position.x -= speed * Global::GetAppTime();
	if (core::Input::IsKeyOn('L'))m_TextureViews[3].m_Constant.m_Position.x += speed * Global::GetAppTime();

	for (auto& textureView : m_TextureViews)
	{
		textureView.update();
	}

	if (core::Input::IsKeyOn('T'))
	{
		Rect rect;
		f32 width = static_cast<f32>(graphic::Config::GetScreenWidth());
		f32 height = static_cast<f32>(graphic::Config::GetScreenHeight());
		Vec4 mousePos = core::Input::GetClientMousePos();
		rect.setSize(mousePos.x / width * 2.0f - 1.0f, mousePos.y / height * -2.0f + 1.0f, 0.1f, 0.1f);
		Model::Primitive::AddRect2D(rect, core::GetColorRGB32(0xff, 0xff, 0x00));
	}
}

// 描画
void GameFlow::Draw()
{
	auto& commandList = graphic::System::GetCommandList();
	m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::RENDER_TARGET);
	commandList.clearRenderTarget(m_MaskDescriptor.getCpuHandle(0), core::GetColorRGBA32(0x00, 0x00, 0x00, 0x00));
	m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

	for (auto& textureView : m_TextureViews)
	{
		textureView.draw();
	}

	graphic::ResourceManager::Regist(m_MaskBuffer);
}

CANDY_APP_NAMESPACE_END
