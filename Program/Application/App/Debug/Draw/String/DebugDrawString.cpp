/*****************************************************************//**
 * \file   DebugDrawString.cpp
 * \brief  文字列のデバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDrawString.h"
#include <App/Font/Font.h>
#include <App/Utility/UtilityConvertPosition.h>

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw
{
	namespace String
	{
#if BUILD_DEBUG
		struct DrawStringInfo
		{
			Vec4 m_Pos{};
			Color m_Color{};
			f32 m_Scale{};
			std::wstring m_Wstring{};
		};
		struct VertexInfo
		{
			Vec4 m_Pos{};
			Vec4 m_Uv{};
			Color m_Color{};
		};
		std::vector<DrawStringInfo> m_DrawStringInfoLists[2];
		std::vector<graphic::Buffer> m_VertexBuffers;
		std::vector<graphic::Buffer> m_IndexBuffers;
		
		graphic::Descriptor m_Descriptor;
		graphic::RootSignature m_RootSignature;
		graphic::Pipeline m_Pipeline;

		core::CriticalSection m_CriticalSection;

		constexpr FONT_TYPE DefaultFontType = FONT_TYPE::GOTHIC;
#endif // BUILD_DEBUG
	}

	// 初期化
	void String::Startup()
	{
#if BUILD_DEBUG
		m_VertexBuffers.resize(graphic::Config::GetBackBufferCount());
		m_IndexBuffers.resize(graphic::Config::GetBackBufferCount());

		graphic::BufferStartupInfo vertexBufferStartupInfo;
		vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * 0xffff);
		for (auto& vertexBuffer : m_VertexBuffers)vertexBuffer.startup(graphic::System::GetDevice(), vertexBufferStartupInfo);

		graphic::BufferStartupInfo indexBufferStartupInfo;
		indexBufferStartupInfo.setBufferStartupInfo(sizeof(u16) * 0xffff);
		for (auto& indexBuffer : m_IndexBuffers)indexBuffer.startup(graphic::System::GetDevice(), indexBufferStartupInfo);

		m_Descriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, 1);
		m_Descriptor.bindingTexture2D(graphic::System::GetDevice(), 0, Font::GetFontTextureBuffer(DefaultFontType), graphic::types::GRAPHIC_FORMAT::BC3_UNORM);

		graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
		rootSignatureStartupInfo.initialize();
		rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL }, 1, graphic::types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
		rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, graphic::types::SHADER_VISIBILITY_TYPE::PIXEL },
			graphic::types::FILTER_TYPE::ANISOTROPIC, graphic::types::TEXTURE_ADDRESS_MODE::CLAMP);
		rootSignatureStartupInfo.setRootParameterCount(1);
		rootSignatureStartupInfo.setStaticSamplerCount(1);
		rootSignatureStartupInfo.onRootSignatureFlag(graphic::types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature.startup(graphic::System::GetDevice(), rootSignatureStartupInfo);

		graphic::PipelineStartupInfo pipelineStartupInfo;
		pipelineStartupInfo.initialize();
		pipelineStartupInfo.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::DEBUG_STRING));
		pipelineStartupInfo.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::DEBUG_STRING));
		pipelineStartupInfo.setInputLayoutElement(0, graphic::types::SHADER_SEMANTIC_TYPE::POSITION, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(1, graphic::types::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(2, graphic::types::SHADER_SEMANTIC_TYPE::COLOR, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutCount(3);
		pipelineStartupInfo.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo.setRenderTaretCount(1);
		pipelineStartupInfo.setEnableDepth(false);
		pipelineStartupInfo.setEnableBlend(0, true);
		pipelineStartupInfo.setRootSignature(m_RootSignature);
		m_Pipeline.startup(graphic::System::GetDevice(), pipelineStartupInfo);

		m_CriticalSection.startup();
#endif // BUILD_DEBUG
	}

	// 破棄
	void String::Cleanup()
	{
#if BUILD_DEBUG
		m_CriticalSection.cleanup();

		for (auto& vertexBuffer : m_VertexBuffers)vertexBuffer.cleanup();
		for (auto& indexBuffer : m_IndexBuffers)indexBuffer.cleanup();
		m_VertexBuffers.clear();
		m_IndexBuffers.clear();
#endif // BUILD_DEBUG
	}

	// 更新
	void String::Update()
	{
#if BUILD_DEBUG
#endif // BUILD_DEBUG
	}

	// 描画
	void String::Draw()
	{
#if BUILD_DEBUG
		auto& drawStringInfoList = m_DrawStringInfoLists[Global::GetDrawIndex()];
		if (drawStringInfoList.empty())return;

		std::vector<VertexInfo> vertexInfos;
		std::vector<u16> indices;
		u16 index = 0;

		const f32 screenRate = (f32)graphic::Config::GetScreenHeight() / (f32)graphic::Config::GetScreenWidth();

		for (const auto& drawStringInfo : drawStringInfoList)
		{
			Vec4 pos = drawStringInfo.m_Pos;
			const f32 heightSize = drawStringInfo.m_Scale / graphic::Config::GetScreenHeight();
			for (auto c : drawStringInfo.m_Wstring)
			{
				if (c == u'\0')break;
				if (c == u'\n')
				{
					pos.x = drawStringInfo.m_Pos.x;
					pos.y += -heightSize * 2.0f;
					continue;
				}
				if (c == u' ')
				{
					const Rect rect = Font::GetFontUv(DefaultFontType, '?');
					pos.x += rect.m_Width * (heightSize / rect.m_Height) * screenRate * 2.0f;
					continue;
				}
				if (c == u'　')
				{
					const Rect rect = Font::GetFontUv(DefaultFontType, '？');
					pos.x += rect.m_Width * (heightSize / rect.m_Height) * screenRate * 2.0f;
					continue;
				}
				const Rect rect = Font::GetFontUv(DefaultFontType, c);

				const f32 width = rect.m_Width * (heightSize / rect.m_Height) * screenRate * 2.0f;
				const f32 height = -heightSize * 2.0f;

				VertexInfo vertexInfo1, vertexInfo2, vertexInfo3, vertexInfo4;
				vertexInfo1.m_Pos = pos;
				vertexInfo1.m_Uv = Vec4{ rect.m_X, rect.m_Y, 0.0f };

				vertexInfo2.m_Pos = pos + Vec4{ width, 0.0f, 0.0f };
				vertexInfo2.m_Uv = Vec4{ rect.m_X + rect.m_Width, rect.m_Y, 0.0f };

				vertexInfo3.m_Pos = pos + Vec4{ 0.0f, height, 0.0f };
				vertexInfo3.m_Uv = Vec4{ rect.m_X, rect.m_Y + rect.m_Height, 0.0f };

				vertexInfo4.m_Pos = pos + Vec4{ width, height, 0.0f };
				vertexInfo4.m_Uv = Vec4{ rect.m_X + rect.m_Width, rect.m_Y + rect.m_Height, 0.0f };

				vertexInfo1.m_Color = drawStringInfo.m_Color;
				vertexInfo2.m_Color = drawStringInfo.m_Color;
				vertexInfo3.m_Color = drawStringInfo.m_Color;
				vertexInfo4.m_Color = drawStringInfo.m_Color;

				pos.x += width;

				vertexInfos.push_back(vertexInfo1);
				vertexInfos.push_back(vertexInfo2);
				vertexInfos.push_back(vertexInfo3);
				vertexInfos.push_back(vertexInfo4);

				indices.push_back(index + 0);
				indices.push_back(index + 1);
				indices.push_back(index + 2);
				indices.push_back(index + 1);
				indices.push_back(index + 3);
				indices.push_back(index + 2);
				index += 4;
			}
		}

		drawStringInfoList.clear();

		m_VertexBuffers[graphic::System::GetBackBufferIndex()].store(reinterpret_cast<std::byte*>(vertexInfos.data()), core::Min(vertexInfos.size(), 0xffff) * sizeof(VertexInfo), 0);
		m_IndexBuffers[graphic::System::GetBackBufferIndex()].store(reinterpret_cast<std::byte*>(indices.data()), core::Min(indices.size(), 0xffff) * sizeof(u16), 0);

		auto& commandList = graphic::System::GetCommandList();

		commandList.setRenderTargets(graphic::System::GetBackBufferDescriptor().getCpuHandle(graphic::System::GetBackBufferIndex()), 1);

		commandList.setRootSignature(m_RootSignature);
		commandList.setPipeline(m_Pipeline);

		Font::GetFontTextureBuffer(DefaultFontType).translationBarrier(commandList, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

		commandList.setDescriptor(0, m_Descriptor);
		commandList.registDescriptors(1, 0);
		commandList.setDescriptorTable(0, m_Descriptor, 0);

		graphic::VertexBufferView vertexBufferView;
		vertexBufferView.startup(m_VertexBuffers[graphic::System::GetBackBufferIndex()], 0, (u32)vertexInfos.size(), sizeof(VertexInfo));
		graphic::IndexBufferView indexBufferView;
		indexBufferView.startup(m_IndexBuffers[graphic::System::GetBackBufferIndex()], 0, (u32)indices.size(), sizeof(u16), graphic::types::GRAPHIC_FORMAT::R16_UINT);
		commandList.setVertexBuffer(0, vertexBufferView);
		commandList.registVertexBuffers(1);
		commandList.setIndexBuffer(indexBufferView);
		commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		commandList.drawIndexedInstanced(indexBufferView.getIndexCount(), 1, 0, 0, 0);

		graphic::ResourceManager::Regist(m_VertexBuffers[graphic::System::GetBackBufferIndex()]);
		graphic::ResourceManager::Regist(m_IndexBuffers[graphic::System::GetBackBufferIndex()]);
		graphic::ResourceManager::Regist(Font::GetFontTextureBuffer(DefaultFontType));
#endif // BUILD_DEBUG
	}

	// 描画登録(位置, 色, サイズ)
	void String::Add(
		CANDY_UNUSED_VALUE_ATTR const AddInfo& _addInfo, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _format)
	{
#if BUILD_DEBUG
		DrawStringInfo drawStringInfo;
		drawStringInfo.m_Pos = Utility::ToScreenPosFrom2DPos(_addInfo.m_Pos);
		drawStringInfo.m_Color = _addInfo.m_Color;
		drawStringInfo.m_Scale = _addInfo.m_Scale;
		drawStringInfo.m_Wstring = core::StringSystem::ConvertMultiByteToWideCharSJIS(_format);
		CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
		m_DrawStringInfoLists[Global::GetUpdateIndex()].push_back(drawStringInfo);
#endif // BUILD_DEBUG
	}
}

CANDY_APP_NAMESPACE_END
