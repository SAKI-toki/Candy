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
#include <App/Entity/EntityManager.h>
#include <App/Component/System/AllComponentInclude.h>
#include <App/Rendering/RenderingManager.h>

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
			core::FileSystem::BufferInfo bufferInfo;
			core::FileSystem::RequestReadNoWait(path, &bufferInfo);
			auto result = graphic::Texture::DDS::ReadAlloc(bufferInfo.m_Buffer, bufferInfo.m_BufferSize);
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
			auto& commandList = RenderingManager::GetModelCommandList();

			if(flag & STARTUP_FLAG_WRITE_MASK)
			{
				//m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::RENDER_TARGET);
				commandList.setRenderTargets(m_MaskDescriptor.getCpuHandle(0), 1);
			}

			commandList.setRootSignature(m_RootSignature);
			commandList.setPipeline(m_Pipeline);

			//m_TextureBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

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
				//m_MaskBuffer.translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
				commandList.setRenderTargets(graphic::System::GetBackBufferDescriptor().getCpuHandle(graphic::System::GetBackBufferIndex()), 1);
			}

			graphic::ResourceManager::Regist(m_VertexBuffer);
			graphic::ResourceManager::Regist(m_IndexBuffer);
			graphic::ResourceManager::Regist(m_ConstantBuffer);
			graphic::ResourceManager::Regist(m_TextureBuffer);
		}

		struct Constant
		{
			Vec4 m_Pos{};
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

	std::vector<EntityHandle> m_Entities;
}

// 初期化
void GameFlow::Startup()
{
	auto player = EntityManager::CreateEntity("Player");
	player->addComponent<Component::PlayerBehavior>();
	player->addComponent<Component::Renderer>();
	if (auto transform = player->getTransformComponent())
	{
		transform->setPos({ 100.0f, 100.0f, 0.0f });
		transform->setScale({ 20.0f, 40.0f, 0.0f });
	}
	m_Entities.push_back(player->getHandle());

	auto enemy = EntityManager::CreateEntity("Enemy");
	enemy->addComponent<Component::EnemyBehavior>();
	enemy->addComponent<Component::Renderer>();
	if (auto transform = enemy->getTransformComponent())
	{
		transform->setPos({ 200.0f, 200.0f, 0.0f });
		transform->setScale({ 70.0f, 30.0f, 0.0f });
	}
	m_Entities.push_back(enemy->getHandle());

	if (auto component = player->getComponent<Component::PlayerBehavior>())
	{
		component->setEnemyEntityHandle(enemy->getHandle());
	}
}

// 破棄
void GameFlow::Cleanup()
{
	for (const auto& entity : m_Entities)EntityManager::ReleaseEntity(entity);
	m_Entities.clear();
}

// 更新
void GameFlow::Update()
{

}

// 描画
void GameFlow::Draw()
{

}

CANDY_APP_NAMESPACE_END
