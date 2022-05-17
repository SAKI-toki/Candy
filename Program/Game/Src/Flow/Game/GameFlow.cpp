#include "GameFlow.h"
#include <Flow/Scene/SceneFlow.h>
#include <Input/Input.h>

#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/BufferView/Vertex/GraphicVertexBufferView.h>
#include <Graphic/BufferView/Index/GraphicIndexBufferView.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Shader/Shader.h>
#include <Texture/Texture.h>
#include <Texture/DDS/ReadDDS.h>
#include <Graphic/ResourceManager/GraphicResourceManager.h>
#include <Sound/Sound.h>

CANDY_NAMESPACE_BEGIN

namespace GameFlow
{
	std::vector<Graphic::Buffer> m_MaskBuffers;
	Graphic::Descriptor m_MaskDescriptor;

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
			m_Descriptor.startup(Graphic::GetDevice(), Graphic::DESCRIPTOR_TYPE::CBV_SRV_UAV, Graphic::GetBackBufferCount() * 2 + 1);

			Graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
			rootSignatureStartupInfo.initialize();
			rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, Graphic::SHADER_VISIBILITY_TYPE::ALL }, Graphic::GetBackBufferCount(), Graphic::DESCRIPTOR_RANGE_TYPE::CONSTANT_BUFFER);
			rootSignatureStartupInfo.setDescriptorRange(1, { 0, 0, Graphic::SHADER_VISIBILITY_TYPE::PIXEL }, 1, Graphic::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
			rootSignatureStartupInfo.setDescriptorRange(2, { 1, 0, Graphic::SHADER_VISIBILITY_TYPE::PIXEL }, Graphic::GetBackBufferCount(), Graphic::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
			rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, Graphic::SHADER_VISIBILITY_TYPE::PIXEL },
				Graphic::FILTER_TYPE::ANISOTROPIC, Graphic::TEXTURE_ADDRESS_MODE::CLAMP);
			rootSignatureStartupInfo.setRootParameterCount(3);
			if (_startupFlag & STARTUP_FLAG_WRITE_MASK)
			{
				rootSignatureStartupInfo.setRootParameterCount(2);
			}
			rootSignatureStartupInfo.setStaticSamplerCount(1);
			rootSignatureStartupInfo.onRootSignatureFlag(Graphic::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
			m_RootSignature.startup(Graphic::GetDevice(), rootSignatureStartupInfo);

			Graphic::PipelineStartupInfo pipelineStartupInfo;
			pipelineStartupInfo.initialize();
			pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::TEST));
			pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::TEST));
			pipelineStartupInfo.setInputLayoutElement(0, Graphic::SHADER_SEMANTIC_TYPE::POSITION, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(1, Graphic::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(2, Graphic::SHADER_SEMANTIC_TYPE::COLOR, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutCount(3);
			pipelineStartupInfo.setDepthStencilFormat(Graphic::GRAPHIC_FORMAT::D24_UNORM_S8_UINT);
			pipelineStartupInfo.setRenderTaretFormat(0, Graphic::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
			if (_startupFlag & STARTUP_FLAG_WRITE_MASK)
			{
				pipelineStartupInfo.setRenderTaretFormat(0, Graphic::GRAPHIC_FORMAT::A8_UINT);
				pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::TEST_MASK));
				pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::TEST_MASK));
			}
			pipelineStartupInfo.setRenderTaretCount(1);
			pipelineStartupInfo.setEnableDepth(false);
			pipelineStartupInfo.setEnableBlend(0, true);
			pipelineStartupInfo.setRootSignature(m_RootSignature);
			m_Pipeline.startup(Graphic::GetDevice(), pipelineStartupInfo);

			VertexInfo vertices[] =
			{
				{ Vec4{ -0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 0.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ¶ã
				{ Vec4{ +0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 0.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ‰Eã
				{ Vec4{ -0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 1.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ¶‰º
				{ Vec4{ +0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 1.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ‰E‰º
			};
			Graphic::BufferStartupInfo vertexBufferStartupInfo;
			vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * GetArraySize(vertices));
			m_VertexBuffer.startup(Graphic::GetDevice(), vertexBufferStartupInfo);
			m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * GetArraySize(vertices), 0);

			u32 indices[] =
			{
				0, 1, 2,
				1, 3, 2,
			};
			Graphic::BufferStartupInfo indexBufferStartupInfo;
			indexBufferStartupInfo.setBufferStartupInfo(sizeof(u32) * GetArraySize(indices));
			m_IndexBuffer.startup(Graphic::GetDevice(), indexBufferStartupInfo);
			m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u32) * GetArraySize(indices), 0);

			Graphic::BufferStartupInfo constantBufferStartupInfo;
			constantBufferStartupInfo.setBufferStartupInfo(0x100 * Graphic::GetBackBufferCount());
			m_ConstantBuffer.startup(Graphic::GetDevice(), constantBufferStartupInfo);
			for (s32 i = 0; i < Graphic::GetBackBufferCount(); ++i)
			{
				m_Descriptor.bindingConstantBuffer(Graphic::GetDevice(), i, m_ConstantBuffer, 0x100 * i, 0x100);
			}

			Graphic::GRAPHIC_FORMAT format = (_startupFlag & STARTUP_FLAG_USE_ALPHA) ? Graphic::GRAPHIC_FORMAT::BC3_UNORM : Graphic::GRAPHIC_FORMAT::BC1_UNORM;
			Graphic::BufferStartupInfo textureBufferStartupInfo;
			textureBufferStartupInfo.setTextureStartupInfo(format, _width, _height);
			m_TextureBuffer.startup(Graphic::GetDevice(), textureBufferStartupInfo);
			m_Descriptor.bindingTexture2D(Graphic::GetDevice(), Graphic::GetBackBufferCount() * 2, m_TextureBuffer, format);

			for (s32 i = 0; i < Graphic::GetBackBufferCount(); ++i)
			{
				m_Descriptor.bindingTexture2D(Graphic::GetDevice(), Graphic::GetBackBufferCount() + i, m_MaskBuffers[i], Graphic::GRAPHIC_FORMAT::A8_UINT);
			}

			auto path = std::string{ Setting::GetDataPath() } + _texturePath;
			u64 size = FileSystem::GetFileSize(path);
			std::byte* buf = new std::byte[size];
			FileSystem::RequestReadNoWait(path, buf, size);
			auto result = Texture::DDS::ReadAlloc(buf, size);
			Texture::CreateTexture(m_TextureBuffer, result, _width * _height / ((_startupFlag & STARTUP_FLAG_USE_ALPHA) ? 1 : 2));
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
			m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&m_Constant), sizeof(m_Constant), 0x100 * Graphic::GetBackBufferIndex());
		}
		void draw()
		{
			auto& commandList = Graphic::GetCommandList();

			if(flag & STARTUP_FLAG_WRITE_MASK)
			{
				m_MaskBuffers[Graphic::GetBackBufferIndex()].translationBarrier(commandList, Graphic::BARRIER_STATE::RENDER_TARGET);
				commandList.setRenderTargets(m_MaskDescriptor.getCpuHandle(Graphic::GetBackBufferIndex()), 1);
			}

			commandList.setRootSignature(m_RootSignature);
			commandList.setPipeline(m_Pipeline);

			m_TextureBuffer.translationBarrier(commandList, Graphic::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

			commandList.setDescriptor(0, m_Descriptor);
			commandList.registDescriptors(1, 0);
			commandList.setDescriptorTable(0, m_Descriptor, Graphic::GetBackBufferIndex());
			commandList.setDescriptorTable(1, m_Descriptor, Graphic::GetBackBufferCount() * 2);
			if (!(flag & STARTUP_FLAG_WRITE_MASK))
			{
				commandList.setDescriptorTable(2, m_Descriptor, Graphic::GetBackBufferCount() + Graphic::GetBackBufferIndex());
			}

			Graphic::VertexBufferView vertexBufferView;
			vertexBufferView.startup(m_VertexBuffer, 0, 4, sizeof(VertexInfo));
			Graphic::IndexBufferView indexBufferView;
			indexBufferView.startup(m_IndexBuffer, 0, 6, sizeof(u32), Graphic::GRAPHIC_FORMAT::R32_UINT);
			commandList.setVertexBuffer(0, vertexBufferView);
			commandList.registVertexBuffers(1);
			commandList.setIndexBuffer(indexBufferView);
			commandList.setPrimitiveTopology(Graphic::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
			commandList.drawIndexedInstanced(indexBufferView.getIndexCount(), 1, 0, 0, 0);

			if (flag & STARTUP_FLAG_WRITE_MASK)
			{
				m_MaskBuffers[Graphic::GetBackBufferIndex()].translationBarrier(commandList, Graphic::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
				commandList.setRenderTargets(Graphic::GetBackBufferDescriptor().getCpuHandle(Graphic::GetBackBufferIndex()), 1);
			}

			Graphic::ResourceManager::Regist(m_VertexBuffer);
			Graphic::ResourceManager::Regist(m_IndexBuffer);
			Graphic::ResourceManager::Regist(m_ConstantBuffer);
			Graphic::ResourceManager::Regist(m_TextureBuffer);
		}

		struct Constant
		{
			Vec4 m_Position{};
			Color m_Color{ CANDY_COLOR_RGB32(0xff, 0xff, 0xff) };
			Vec4 pad[14];
		}m_Constant;
	private:
		Graphic::Descriptor m_Descriptor;
		Graphic::RootSignature m_RootSignature;
		Graphic::Pipeline m_Pipeline;
		Graphic::Buffer m_VertexBuffer;
		Graphic::Buffer m_IndexBuffer;
		Graphic::Buffer m_ConstantBuffer;
		Graphic::Buffer m_TextureBuffer;
	};

	TextureView m_TextureViews[4];
}

void GameFlow::Startup()
{
	Input::Startup();

	Graphic::BufferStartupInfo bufferStartupInfo;
	bufferStartupInfo.setRenderTargetStartupInfo(Graphic::GRAPHIC_FORMAT::A8_UINT, Graphic::GetScreenWidth(), Graphic::GetScreenHeight());
	m_MaskDescriptor.startup(Graphic::GetDevice(), Graphic::DESCRIPTOR_TYPE::RENDER_TARGET, Graphic::GetBackBufferCount());
	m_MaskBuffers.resize(Graphic::GetBackBufferCount());
	for (s32 i = 0; i < Graphic::GetBackBufferCount(); ++i)
	{
		m_MaskBuffers[i].startup(Graphic::GetDevice(), bufferStartupInfo);
		m_MaskDescriptor.bindingRenderTarget(Graphic::GetDevice(), i, m_MaskBuffers[i], Graphic::GRAPHIC_FORMAT::A8_UINT);
	}

	m_TextureViews[0].startup(R"(Texture\forest.dds)", 512, 256, Vec4{ 8.0f * 9 / 16, 4.0f * 9 / 16, 1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[1].startup(R"(Texture\house.dds)", 256, 256, Vec4{ 2.0f,2.0f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[2].startup(R"(Texture\player1.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_USE_ALPHA);
	m_TextureViews[3].startup(R"(Texture\player2.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[2].m_Constant.m_Position.m_f32.y = -0.65f;
	m_TextureViews[3].m_Constant.m_Position.m_f32.y = -0.65f;

	Sound::CallSe("TestSound.wav");
}

void GameFlow::Cleanup()
{
	for (auto& textureView : m_TextureViews)textureView.cleanup();
	Input::Cleanup();
}

void GameFlow::Update()
{
	Input::Update();

	constexpr f32 speed = 0.3f;
	static bool isLanding = true;
	static bool isSideVelocity = false;
	static f32 velocity = 0.0f;
	static f32 sideVelocity = 0.0f;
	if (Input::IsKeyTrigger('A'))
	{
		sideVelocity -= 4.0f;
		isSideVelocity = true;
	}
	if (Input::IsKeyTrigger('D'))
	{
		sideVelocity += 4.0f;
		isSideVelocity = true;
	}
	if (Input::IsKeyTrigger('W'))
	{
		if (isLanding)velocity = 4.0f;
		isLanding = false;
	}
	if (!isLanding)
	{
		m_TextureViews[2].m_Constant.m_Position.m_f32.y += velocity * Global::GetAppTime();
		velocity -= 9.8f * Global::GetAppTime();
	}

	if (isSideVelocity)
	{
		m_TextureViews[2].m_Constant.m_Position.m_f32.x += sideVelocity * Global::GetAppTime();
		auto prevSideVelocity = sideVelocity;
		sideVelocity -= 9.8f * Global::GetAppTime() * (sideVelocity > 0.0f ? 1.0f : -1.0f);
		if (prevSideVelocity > 0.0f && sideVelocity <= 0.0f ||
			prevSideVelocity < 0.0f && sideVelocity >= 0.0f)
		{
			sideVelocity = 0.0f;
			isSideVelocity = false;
		}
	}
	if (m_TextureViews[2].m_Constant.m_Position.m_f32.y <= -0.65f)
	{
		m_TextureViews[2].m_Constant.m_Position.m_f32.y = -0.65f;
		velocity = 0.0f;
		isLanding = true;
	}
	if (m_TextureViews[2].m_Constant.m_Position.m_f32.x > 0.7f ||
		m_TextureViews[2].m_Constant.m_Position.m_f32.x < -0.8f)
	{
		m_TextureViews[2].m_Constant.m_Position.m_f32.x = Clamp(m_TextureViews[2].m_Constant.m_Position.m_f32.x, -0.8f, 0.7f);
		sideVelocity = 0.0f;
		isSideVelocity = true;
	}

	if (Input::IsKeyOn('J'))m_TextureViews[3].m_Constant.m_Position.m_f32.x -= speed * Global::GetAppTime();
	if (Input::IsKeyOn('L'))m_TextureViews[3].m_Constant.m_Position.m_f32.x += speed * Global::GetAppTime();

	for (auto& textureView : m_TextureViews)
	{
		textureView.update();
	}
}

void GameFlow::Draw()
{
	auto& commandList = Graphic::GetCommandList();
	const s32 backBufferindex = Graphic::GetBackBufferIndex();
	m_MaskBuffers[backBufferindex].translationBarrier(commandList, Graphic::BARRIER_STATE::RENDER_TARGET);
	commandList.clearRenderTarget(m_MaskDescriptor.getCpuHandle(backBufferindex), CANDY_COLOR_RGBA32(0x00, 0x00, 0x00, 0x00));
	m_MaskBuffers[backBufferindex].translationBarrier(commandList, Graphic::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

	for (auto& textureView : m_TextureViews)
	{
		textureView.draw();
	}

	Graphic::ResourceManager::Regist(m_MaskBuffers[Graphic::GetBackBufferIndex()]);
}

CANDY_NAMESPACE_END

