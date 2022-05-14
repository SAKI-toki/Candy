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

CANDY_NAMESPACE_BEGIN

namespace GameFlow
{
	class TextureView
	{
	public:
		enum STARTUP_FLAG
		{
			STARTUP_FLAG_NONE = 0,
			STARTUP_FLAG_USE_ALPHA = (1 << 0),
			STARTUP_FLAG_WRITE_MASK = (1 << 1),
		};
		void startup(const std::string& _texturePath, const u32 _width, const u32 _height, const Vec4 _scale, const STARTUP_FLAG _startupFlag)
		{
			using namespace Graphic;
			m_Descriptor.startup(GetDevice(), DESCRIPTOR_TYPE::CONSTANT_BUFFER, GetBackBufferCount());
			m_TextureDescriptor.startup(GetDevice(), DESCRIPTOR_TYPE::SHADER_RESOURCE, 1);

			RootSignatureStartupInfo rootSignatureStartupInfo;
			rootSignatureStartupInfo.initialize();
			rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, SHADER_VISIBILITY_TYPE::ALL }, m_Descriptor);
			rootSignatureStartupInfo.setDescriptorRange(1, { 0, 0, SHADER_VISIBILITY_TYPE::PIXEL }, m_TextureDescriptor);
			rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, SHADER_VISIBILITY_TYPE::PIXEL },
				FILTER_TYPE::ANISOTROPIC, TEXTURE_ADDRESS_MODE::CLAMP);
			rootSignatureStartupInfo.setRootParameterCount(2);
			rootSignatureStartupInfo.setStaticSamplerCount(1);
			rootSignatureStartupInfo.onRootSignatureFlag(ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
			m_RootSignature.startup(GetDevice(), rootSignatureStartupInfo);

			PipelineStartupInfo pipelineStartupInfo;
			pipelineStartupInfo.initialize();
			pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::TEST));
			pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::TEST));
			pipelineStartupInfo.setInputLayoutElement(0, SHADER_SEMANTIC_TYPE::POSITION, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(1, SHADER_SEMANTIC_TYPE::TEXCOORD, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutElement(2, SHADER_SEMANTIC_TYPE::COLOR, 0, GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
			pipelineStartupInfo.setInputLayoutCount(3);
			pipelineStartupInfo.setDepthStencilFormat(GRAPHIC_FORMAT::D24_UNORM_S8_UINT);
			pipelineStartupInfo.setRenderTaretFormat(0, GRAPHIC_FORMAT::R8G8B8A8_UNORM);
			pipelineStartupInfo.setRenderTaretCount(1);
			if (_startupFlag & STARTUP_FLAG_WRITE_MASK)
			{
				pipelineStartupInfo.setEnableStencil(true);
			}
			pipelineStartupInfo.setEnableDepth(false);
			pipelineStartupInfo.setEnableBlend(0, true);
			pipelineStartupInfo.setRootSignature(m_RootSignature);
			m_Pipeline.startup(GetDevice(), pipelineStartupInfo);

			struct VertexInfo
			{
				Vec4 position;
				Vec4 texcoord;
				Color color;
			};
			VertexInfo vertices[] =
			{
				{ Vec4{ -0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 0.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ¶ã
				{ Vec4{ +0.25f, +0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 0.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ‰Eã
				{ Vec4{ -0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 0.0f, 1.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ¶‰º
				{ Vec4{ +0.25f, -0.25f * 16 / 9, 0.0f } *_scale,{ 1.0f, 1.0f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0xff, 0xff, 0xff) }, // ‰E‰º
			};
			BufferStartupInfo vertexBufferStartupInfo;
			vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * GetArraySize(vertices));
			m_VertexBuffer.startup(GetDevice(), vertexBufferStartupInfo);
			m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * GetArraySize(vertices), 0);
			m_VertexBufferView.startup(m_VertexBuffer, 0, GetArraySize(vertices), sizeof(VertexInfo));

			u32 indices[] =
			{
				0, 1, 2,
				1, 3, 2,
			};
			BufferStartupInfo indexBufferStartupInfo;
			indexBufferStartupInfo.setBufferStartupInfo(sizeof(u32) * GetArraySize(indices));
			m_IndexBuffer.startup(GetDevice(), indexBufferStartupInfo);
			m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u32) * GetArraySize(indices), 0);
			m_IndexBufferView.startup(m_IndexBuffer, 0, GetArraySize(indices), sizeof(u32), GRAPHIC_FORMAT::R32_UINT);

			BufferStartupInfo constantBufferStartupInfo;
			constantBufferStartupInfo.setBufferStartupInfo(0x100 * GetBackBufferCount());
			m_ConstantBuffer.startup(GetDevice(), constantBufferStartupInfo);
			for (s32 i = 0; i < GetBackBufferCount(); ++i)
			{
				m_Descriptor.bindingConstantBuffer(GetDevice(), i, m_ConstantBuffer, 0x100 * i, 0x100);
			}

			GRAPHIC_FORMAT format = (_startupFlag & STARTUP_FLAG_USE_ALPHA) ? GRAPHIC_FORMAT::BC3_UNORM : GRAPHIC_FORMAT::BC1_UNORM;
			BufferStartupInfo textureBufferStartupInfo;
			textureBufferStartupInfo.setTextureStartupInfo(format, _width, _height);
			m_TextureBuffer.startup(GetDevice(), textureBufferStartupInfo);
			m_TextureDescriptor.bindingTexture2D(GetDevice(), 0, m_TextureBuffer, format);

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
			m_VertexBufferView.cleanup();
			m_IndexBufferView.cleanup();
			m_TextureBuffer.cleanup();
			m_TextureDescriptor.cleanup();
		}
		void update()
		{
			m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&m_Constant), sizeof(m_Constant), 0x100 * Graphic::GetBackBufferIndex());
		}
		void draw()
		{
			auto& commandList = Graphic::GetCommandList();
			commandList.setRootSignature(m_RootSignature);
			commandList.setPipeline(m_Pipeline);
			commandList.setPrimitiveTopology(Graphic::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);

			commandList.setDescriptor(0, m_Descriptor);
			commandList.registDescriptors(1);
			commandList.setDescriptorTable(0, m_Descriptor, Graphic::GetBackBufferIndex());
			commandList.setDescriptor(0, m_TextureDescriptor);
			commandList.registDescriptors(1);
			commandList.setDescriptorTable(1, m_TextureDescriptor, 0);
			commandList.setIndexBuffer(m_IndexBufferView);
			commandList.setVertexBuffer(0, m_VertexBufferView);
			commandList.registVertexBuffers(1);
			commandList.drawIndexedInstanced(m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);

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
		Graphic::VertexBufferView m_VertexBufferView;
		Graphic::IndexBufferView m_IndexBufferView;
		Graphic::Buffer m_TextureBuffer;
		Graphic::Descriptor m_TextureDescriptor;
	};

	TextureView m_TextureViews[4];
}

void GameFlow::Startup()
{
	Input::Startup();

	m_TextureViews[0].startup(R"(Texture\forest.dds)", 512, 256, Vec4{ 8.0f * 9 / 16, 4.0f * 9 / 16, 1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[1].startup(R"(Texture\house.dds)", 256, 256, Vec4{ 2.0f,2.0f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[2].startup(R"(Texture\player1.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_USE_ALPHA);
	m_TextureViews[3].startup(R"(Texture\player2.dds)", 256, 256, Vec4{ 0.5f,0.5f,1.0f }, TextureView::STARTUP_FLAG_NONE);
	m_TextureViews[0].m_Constant.m_Position.m_f32.y = -0.65f;
	m_TextureViews[1].m_Constant.m_Position.m_f32.y = -0.65f;
	m_TextureViews[2].m_Constant.m_Position.m_f32.y = -0.65f;
	m_TextureViews[3].m_Constant.m_Position.m_f32.y = -0.65f;
	m_TextureViews[3].m_Constant.m_Color.m_f32Col.r = 0.5f;
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


	if (Input::IsKeyOn('J'))m_TextureViews[3].m_Constant.m_Position.m_f32.x -= speed * Global::GetAppTime();
	if (Input::IsKeyOn('L'))m_TextureViews[3].m_Constant.m_Position.m_f32.x += speed * Global::GetAppTime();

	for (auto& textureView : m_TextureViews)
	{
		textureView.update();
	}
}

void GameFlow::Draw()
{
	for (auto& textureView : m_TextureViews)
	{
		textureView.draw();
	}
}

CANDY_NAMESPACE_END

