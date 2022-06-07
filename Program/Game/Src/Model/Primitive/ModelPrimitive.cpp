/*****************************************************************//**
 * \file   ModelPrimitive.cpp
 * \brief  ÉvÉäÉ~ÉeÉBÉuÉÇÉfÉã
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "ModelPrimitive.h"
#include <Graphic/Graphic.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/BufferView/Vertex/GraphicVertexBufferView.h>
#include <Graphic/BufferView/Index/GraphicIndexBufferView.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/ResourceManager/GraphicResourceManager.h>
#include <Shader/Shader.h>

CANDY_NAMESPACE_BEGIN

namespace Model
{
	namespace Primitive
	{
		Graphic::RootSignature m_RootSignature2D;
		Graphic::Pipeline m_Pipeline2D;
		std::vector<Graphic::Buffer> m_VertexBufferList2D;
		std::vector<Graphic::Buffer> m_IndexBufferList2D;
		std::vector<VertexInfo> m_VertexInfos2D;
		std::vector<u16> m_Indices2D;
	}

	// èâä˙âª
	void Primitive::Startup()
	{
		Graphic::RootSignatureStartupInfo rootSignatureStartupInfo2D;
		rootSignatureStartupInfo2D.initialize();
		rootSignatureStartupInfo2D.setRootParameterCount(0);
		rootSignatureStartupInfo2D.setStaticSamplerCount(0);
		rootSignatureStartupInfo2D.onRootSignatureFlag(Graphic::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature2D.startup(Graphic::GetDevice(), rootSignatureStartupInfo2D);

		Graphic::PipelineStartupInfo pipelineStartupInfo2D;
		pipelineStartupInfo2D.initialize();
		pipelineStartupInfo2D.setEnableDepth(false);
		pipelineStartupInfo2D.setEnableBlend(0, true);
		pipelineStartupInfo2D.setVertexShader(Shader::GetVertexShader(SHADER_TYPE::PRIMITIVE_2D));
		pipelineStartupInfo2D.setPixelShader(Shader::GetPixelShader(SHADER_TYPE::PRIMITIVE_2D));
		pipelineStartupInfo2D.setInputLayoutElement(0, Graphic::SHADER_SEMANTIC_TYPE::POSITION, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo2D.setInputLayoutElement(1, Graphic::SHADER_SEMANTIC_TYPE::COLOR, 0, Graphic::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo2D.setInputLayoutCount(2);
		pipelineStartupInfo2D.setRenderTaretFormat(0, Graphic::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo2D.setRenderTaretCount(1);
		pipelineStartupInfo2D.setRootSignature(m_RootSignature2D);
		m_Pipeline2D.startup(Graphic::GetDevice(), pipelineStartupInfo2D);

		m_VertexBufferList2D.resize(Graphic::GetBackBufferCount());
		Graphic::BufferStartupInfo vertexBufferStartupInfo2D;
		vertexBufferStartupInfo2D.setBufferStartupInfo(sizeof(VertexInfo) * 0x10000);
		for (auto& vertexBuffer2D : m_VertexBufferList2D)vertexBuffer2D.startup(Graphic::GetDevice(), vertexBufferStartupInfo2D);

		m_IndexBufferList2D.resize(Graphic::GetBackBufferCount());
		Graphic::BufferStartupInfo indexBufferStartupInfo2D;
		indexBufferStartupInfo2D.setBufferStartupInfo(sizeof(u16) * 0x10000);
		for (auto& indexBuffer2D : m_IndexBufferList2D)indexBuffer2D.startup(Graphic::GetDevice(), indexBufferStartupInfo2D);

		m_VertexInfos2D.reserve(0x10000);
		m_Indices2D.reserve(0x10000);
	}

	// îjä¸
	void Primitive::Cleanup()
	{
		m_Indices2D.clear();
		m_VertexInfos2D.clear();
		for (auto& indexBuffer2D : m_IndexBufferList2D)indexBuffer2D.cleanup();
		m_IndexBufferList2D.clear();
		for (auto& vertexBuffer2D : m_VertexBufferList2D)vertexBuffer2D.cleanup();
		m_VertexBufferList2D.clear();
		m_Pipeline2D.cleanup();
		m_RootSignature2D.cleanup();
	}

	// ï`âÊ
	void Primitive::Draw(Graphic::CommandList& _commandList)
	{
		if (m_VertexInfos2D.empty() || m_Indices2D.empty())return;

		auto& vertexBuffer2D = m_VertexBufferList2D[Graphic::GetBackBufferIndex()];
		auto& indexBuffer2D = m_IndexBufferList2D[Graphic::GetBackBufferIndex()];

		vertexBuffer2D.store(reinterpret_cast<std::byte*>(m_VertexInfos2D.data()), m_VertexInfos2D.size() * sizeof(VertexInfo), 0);
		indexBuffer2D.store(reinterpret_cast<std::byte*>(m_Indices2D.data()), m_Indices2D.size() * sizeof(u16), 0);

		Graphic::VertexBufferView vertexBufferView2D;
		vertexBufferView2D.startup(vertexBuffer2D, 0, static_cast<u32>(m_VertexInfos2D.size()), sizeof(VertexInfo));
		Graphic::IndexBufferView indexBufferView2D;
		indexBufferView2D.startup(indexBuffer2D, 0, static_cast<u32>(m_Indices2D.size()), sizeof(u16), Graphic::GRAPHIC_FORMAT::R16_UINT);

		_commandList.setRootSignature(m_RootSignature2D);
		_commandList.setPipeline(m_Pipeline2D);
		_commandList.setVertexBuffer(0, vertexBufferView2D);
		_commandList.registVertexBuffers(1);
		_commandList.setIndexBuffer(indexBufferView2D);
		_commandList.setPrimitiveTopology(Graphic::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		_commandList.drawIndexedInstanced(static_cast<u32>(m_Indices2D.size()), 1, 0, 0, 0);
		Graphic::ResourceManager::Regist(vertexBuffer2D);
		Graphic::ResourceManager::Regist(indexBuffer2D);
		m_VertexInfos2D.clear();
		m_Indices2D.clear();
	}

	// 2DéOäpå`ÇÃï`âÊìoò^
	void Primitive::AddTriangle2D(const Vec4 _pos, const Color _color)
	{
		AddTriangle2D(
			Vec4{  0.0f,  2.0f / 3.0f, 0.0f } + _pos,
			Vec4{  0.5f, -1.0f / 3.0f, 0.0f } + _pos,
			Vec4{ -0.5f, -1.0f / 3.0f, 0.0f } + _pos,
			_color);
	}
	void Primitive::AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Color _color)
	{
		AddTriangle2D(_point1, _point2, _point3, _color, _color, _color);
	}
	void Primitive::AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3,
		const Color _color1, const Color _color2, const Color _color3)
	{
		AddTriangle2D({ VertexInfo{ _point1, _color1 }, VertexInfo{ _point2, _color2 }, VertexInfo{ _point3, _color3 } });
	}
	void Primitive::AddTriangle2D(const VertexInfo(&_vertices)[3])
	{
		const u16 indices[] = { 0, 1, 2 };
		Add2D(_vertices, 3, indices, 3);
	}

	// 2DãÈå`ÇÃï`âÊìoò^
	void Primitive::AddRect2D(const Vec4 _pos, const Color _color)
	{
		AddRect2D(
			Vec4{ -0.5f,  0.5f, 0.0f } + _pos,
			Vec4{  0.5f,  0.5f, 0.0f } + _pos,
			Vec4{ -0.5f, -0.5f, 0.0f } + _pos,
			Vec4{  0.5f, -0.5f, 0.0f } + _pos,
			_color);
	}
	void Primitive::AddRect2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4, const Color _color)
	{
		AddRect2D(_point1, _point2, _point3, _point4, _color, _color, _color, _color);
	}
	void Primitive::AddRect2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4,
		const Color _color1, const Color _color2, const Color _color3, const Color _color4)
	{
		AddRect2D({ VertexInfo{ _point1, _color1 }, VertexInfo{ _point2, _color2 }, VertexInfo{ _point3, _color3 }, VertexInfo{ _point4, _color4 } });
	}
	void Primitive::AddRect2D(const Rect _rect, const Color _color)
	{
		AddRect2D(_rect, _color, _color, _color, _color);
	}
	void Primitive::AddRect2D(const Rect _rect, const Color _color1, const Color _color2, const Color _color3, const Color _color4)
	{
		const f32 left = _rect.m_X;
		const f32 right = _rect.m_X + _rect.m_Width;
		const f32 down = _rect.m_Y;
		const f32 up = _rect.m_Y + _rect.m_Height;
		const Vec4 leftUp		= Vec4{ left,	up,		0.0f };
		const Vec4 rightUp		= Vec4{ right,	up,		0.0f };
		const Vec4 leftDown		= Vec4{ left,	down,	0.0f };
		const Vec4 rightDown	= Vec4{ right,	down,	0.0f };
		AddRect2D({ VertexInfo{ leftUp, _color1 }, VertexInfo{ rightUp, _color2 }, VertexInfo{ leftDown, _color3 }, VertexInfo{ rightDown, _color4 } });
	}
	void Primitive::AddRect2D(const VertexInfo(&_vertices)[4])
	{
		const u16 indices[] = { 0, 1, 2, 1, 3, 2 };
		Add2D(_vertices, 4, indices, 6);
	}

	// 2DÇÃï`âÊìoò^
	void Primitive::Add2D(const VertexInfo* const _vertices, const s32 _vertexCount, const u16* const _indices, const s32 _indexCount)
	{
		if (m_VertexInfos2D.size() + _vertexCount >= 0x10000)
		{
			CANDY_LOG("í∏ì_ÇÃè„å¿Çí¥Ç¶ÇƒÇ¢Ç‹Ç∑");
			return;
		}
		if (m_Indices2D.size() + _indexCount >= 0x10000)
		{
			CANDY_LOG("ÉCÉìÉfÉbÉNÉXÇÃè„å¿Çí¥Ç¶ÇƒÇ¢Ç‹Ç∑");
			return;
		}

		for (s32 i = 0; i < _indexCount; ++i)m_Indices2D.push_back(_indices[i] + static_cast<u16>(m_VertexInfos2D.size()));
		for (s32 i = 0; i < _vertexCount; ++i)m_VertexInfos2D.push_back(_vertices[i]);
	}
}

CANDY_NAMESPACE_END
