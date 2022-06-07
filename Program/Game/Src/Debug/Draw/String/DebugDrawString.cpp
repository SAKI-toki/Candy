/*****************************************************************//**
 * \file   DebugDrawString.cpp
 * \brief  文字列のデバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDrawString.h"
#include <Graphic/Graphic.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/BufferView/Vertex/GraphicVertexBufferView.h>
#include <Graphic/BufferView/Index/GraphicIndexBufferView.h>
#include <Graphic/ResourceManager/GraphicResourceManager.h>
#include <Font/Font.h>
#include <Shader/Shader.h>

CANDY_NAMESPACE_BEGIN

namespace DebugDraw
{
	namespace String
	{
#if BUILD_DEBUG
		struct DrawStringInfo
		{
			Vec4 m_Pos;
			Color m_Color;
			f32 m_Scale;
			std::wstring m_Wstring;
		};
		struct VertexInfo
		{
			Vec4 m_Pos;
			Vec4 m_Uv;
			Color m_Color;
		};
		std::vector<DrawStringInfo> m_DrawStringInfos;
		std::vector<Graphic::Buffer> m_VertexBuffers;
		std::vector<Graphic::Buffer> m_IndexBuffers;
		
		Graphic::Descriptor m_Descriptor;
		Graphic::RootSignature m_RootSignature;
		Graphic::Pipeline m_Pipeline;

		constexpr FONT_TYPE DefaultFontType = FONT_TYPE::GOTHIC;
#endif // BUILD_DEBUG
	}

	// 初期化
	void String::Startup()
	{
#if BUILD_DEBUG
		m_VertexBuffers.resize(Graphic::GetBackBufferCount());
		m_IndexBuffers.resize(Graphic::GetBackBufferCount());

		Graphic::BufferStartupInfo vertexBufferStartupInfo;
		vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * 0xffff);
		for (auto& vertexBuffer : m_VertexBuffers)vertexBuffer.startup(Graphic::GetDevice(), vertexBufferStartupInfo);

		Graphic::BufferStartupInfo indexBufferStartupInfo;
		indexBufferStartupInfo.setBufferStartupInfo(sizeof(u16) * 0xffff);
		for (auto& indexBuffer : m_IndexBuffers)indexBuffer.startup(Graphic::GetDevice(), indexBufferStartupInfo);

		m_Descriptor.startup(Graphic::GetDevice(), Graphic::DESCRIPTOR_TYPE::CBV_SRV_UAV, 1);
		m_Descriptor.bindingTexture2D(Graphic::GetDevice(), 0, Font::GetFontTextureBuffer(DefaultFontType), Graphic::GRAPHIC_FORMAT::BC3_UNORM);

		Graphic::RootSignatureStartupInfo rootSignatureStartupInfo;
		rootSignatureStartupInfo.initialize();
		rootSignatureStartupInfo.setDescriptorRange(0, { 0, 0, Graphic::SHADER_VISIBILITY_TYPE::PIXEL }, 1, Graphic::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE);
		rootSignatureStartupInfo.setStaticSampler(0, { 0, 0, Graphic::SHADER_VISIBILITY_TYPE::PIXEL },
			Graphic::FILTER_TYPE::ANISOTROPIC, Graphic::TEXTURE_ADDRESS_MODE::CLAMP);
		rootSignatureStartupInfo.setRootParameterCount(1);
		rootSignatureStartupInfo.setStaticSamplerCount(1);
		rootSignatureStartupInfo.onRootSignatureFlag(Graphic::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature.startup(Graphic::GetDevice(), rootSignatureStartupInfo);

		Graphic::PipelineStartupInfo pipelineStartupInfo;
		pipelineStartupInfo.initialize();
		pipelineStartupInfo.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::DEBUG_STRING));
		pipelineStartupInfo.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::DEBUG_STRING));
		pipelineStartupInfo.setInputLayoutElement(0, Graphic::SHADER_SEMANTIC_TYPE::POSITION, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(1, Graphic::SHADER_SEMANTIC_TYPE::TEXCOORD, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutElement(2, Graphic::SHADER_SEMANTIC_TYPE::COLOR, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo.setInputLayoutCount(3);
		pipelineStartupInfo.setRenderTaretFormat(0, Graphic::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo.setRenderTaretCount(1);
		pipelineStartupInfo.setEnableDepth(false);
		pipelineStartupInfo.setEnableBlend(0, true);
		pipelineStartupInfo.setRootSignature(m_RootSignature);
		m_Pipeline.startup(Graphic::GetDevice(), pipelineStartupInfo);
#endif // BUILD_DEBUG
	}

	// 破棄
	void String::Cleanup()
	{
#if BUILD_DEBUG
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
		if (m_DrawStringInfos.empty())return;

		std::vector<VertexInfo> vertexInfos;
		std::vector<u16> indices;
		u16 index = 0;

		const f32 screenRate = (f32)Graphic::GetScreenHeight() / (f32)Graphic::GetScreenWidth();

		for (const auto& drawStringInfo : m_DrawStringInfos)
		{
			Vec4 pos = drawStringInfo.m_Pos;
			const f32 heightSize = drawStringInfo.m_Scale / Graphic::GetScreenHeight();
			for (auto c : drawStringInfo.m_Wstring)
			{
				if (c == u'\0')break;
				if (c == u'\n')
				{
					pos.m_f32.x = drawStringInfo.m_Pos.m_f32.x;
					pos.m_f32.y += -heightSize * 2.0f;
					continue;
				}
				if (c == u' ')
				{
					const Rect rect = Font::GetFontUv(DefaultFontType, '?');
					pos.m_f32.x += rect.m_Width * (heightSize / rect.m_Height) * screenRate * 2.0f;
					continue;
				}
				if (c == u'　')
				{
					const Rect rect = Font::GetFontUv(DefaultFontType, '？');
					pos.m_f32.x += rect.m_Width * (heightSize / rect.m_Height) * screenRate * 2.0f;
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

				pos.m_f32.x += width;

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
		m_DrawStringInfos.clear();

		m_VertexBuffers[Graphic::GetBackBufferIndex()].store(reinterpret_cast<std::byte*>(vertexInfos.data()), Min(vertexInfos.size(), 0xffff) * sizeof(VertexInfo), 0);
		m_IndexBuffers[Graphic::GetBackBufferIndex()].store(reinterpret_cast<std::byte*>(indices.data()), Min(indices.size(), 0xffff) * sizeof(u16), 0);

		auto& commandList = Graphic::GetCommandList();

		commandList.setRenderTargets(Graphic::GetBackBufferDescriptor().getCpuHandle(Graphic::GetBackBufferIndex()), 1);

		commandList.setRootSignature(m_RootSignature);
		commandList.setPipeline(m_Pipeline);

		Font::GetFontTextureBuffer(DefaultFontType).translationBarrier(commandList, Graphic::BARRIER_STATE::PIXEL_SHADER_RESOURCE);

		commandList.setDescriptor(0, m_Descriptor);
		commandList.registDescriptors(1, 0);
		commandList.setDescriptorTable(0, m_Descriptor, 0);

		Graphic::VertexBufferView vertexBufferView;
		vertexBufferView.startup(m_VertexBuffers[Graphic::GetBackBufferIndex()], 0, (u32)vertexInfos.size(), sizeof(VertexInfo));
		Graphic::IndexBufferView indexBufferView;
		indexBufferView.startup(m_IndexBuffers[Graphic::GetBackBufferIndex()], 0, (u32)indices.size(), sizeof(u16), Graphic::GRAPHIC_FORMAT::R16_UINT);
		commandList.setVertexBuffer(0, vertexBufferView);
		commandList.registVertexBuffers(1);
		commandList.setIndexBuffer(indexBufferView);
		commandList.setPrimitiveTopology(Graphic::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		commandList.drawIndexedInstanced(indexBufferView.getIndexCount(), 1, 0, 0, 0);

		Graphic::ResourceManager::Regist(m_VertexBuffers[Graphic::GetBackBufferIndex()]);
		Graphic::ResourceManager::Regist(m_IndexBuffers[Graphic::GetBackBufferIndex()]);
		Graphic::ResourceManager::Regist(Font::GetFontTextureBuffer(DefaultFontType));
#endif // BUILD_DEBUG
	}

	// 描画登録(位置)
	void String::Add(const Vec4 _pos, const std::string& _str)
	{
#if BUILD_DEBUG
		Add(_pos, Color{ 0.0f, 0.0f, 0.0f }, _str);
#else // BUILD_DEBUG
		CANDY_UNUSED_VALUE(_pos);
		CANDY_UNUSED_VALUE(_str);
#endif // BUILD_DEBUG
	}

	// 描画登録(位置, 色)
	void String::Add(const Vec4 _pos, const Color _color, const std::string& _str)
	{
#if BUILD_DEBUG
		Add(_pos, _color, 20.0f, _str);
#else // BUILD_DEBUG
		CANDY_UNUSED_VALUE(_pos);
		CANDY_UNUSED_VALUE(_color);
		CANDY_UNUSED_VALUE(_str);
#endif // BUILD_DEBUG
	}

	// 描画登録(位置, 色, サイズ)
	void String::Add(const Vec4 _pos, const Color _color, const f32 _scale, const std::string& _str)
	{
#if BUILD_DEBUG
		DrawStringInfo drawStringInfo;
		const auto screenWidth = Graphic::GetScreenWidth();
		const auto screenHeight = Graphic::GetScreenHeight();
		drawStringInfo.m_Pos.m_f32.x = (std::abs(_pos.m_f32.x / screenWidth * 2.0f) - 1.0f) * (_pos.m_f32.x >= 0.0f ? 1.0f : -1.0f);
		drawStringInfo.m_Pos.m_f32.y = (std::abs(_pos.m_f32.y / screenHeight * 2.0f) - 1.0f) * (_pos.m_f32.y >= 0.0f ? -1.0f : 1.0f);
		drawStringInfo.m_Color = _color;
		drawStringInfo.m_Scale = _scale;
		drawStringInfo.m_Wstring = StringSystem::ConvertMultiByteToWideCharSJIS(_str);
		m_DrawStringInfos.push_back(drawStringInfo);
#else // BUILD_DEBUG
		CANDY_UNUSED_VALUE(_pos);
		CANDY_UNUSED_VALUE(_color);
		CANDY_UNUSED_VALUE(_scale);
		CANDY_UNUSED_VALUE(_str);
#endif // BUILD_DEBUG
	}
}

CANDY_NAMESPACE_END
