/*****************************************************************//**
 * \file   DebugDrawPrimitive2D.cpp
 * \brief  2Dプリミティブのデバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDrawPrimitive2D.h"
#include <App/Utility/UtilityConvertPosition.h>
#include <App/Rendering/RenderingManager.h>

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw
{
	namespace Primitive2D
	{
#if BUILD_DEBUG
		graphic::RootSignature m_RootSignature2D;
		graphic::Pipeline m_Pipeline2D;
		std::vector<graphic::Buffer> m_VertexBufferList2D;
		std::vector<graphic::Buffer> m_IndexBufferList2D;
		std::vector<VertexInfo> m_VertexInfo2DLists[2];
		std::vector<u16> m_Indices2DLists[2];
		core::CriticalSection m_CriticalSection;
#endif // BUILD_DEBUG
	}

	// 初期化
	void Primitive2D::Startup()
	{
#if BUILD_DEBUG
		graphic::RootSignatureStartupInfo rootSignatureStartupInfo2D;
		rootSignatureStartupInfo2D.initialize();
		rootSignatureStartupInfo2D.setRootParameterCount(0);
		rootSignatureStartupInfo2D.setStaticSamplerCount(0);
		rootSignatureStartupInfo2D.onRootSignatureFlag(graphic::types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);
		m_RootSignature2D.startup(graphic::System::GetDevice(), rootSignatureStartupInfo2D);

		graphic::PipelineStartupInfo pipelineStartupInfo2D;
		pipelineStartupInfo2D.initialize();
		pipelineStartupInfo2D.setEnableDepth(false);
		pipelineStartupInfo2D.setEnableBlend(0, true);
		pipelineStartupInfo2D.setVertexShader(graphic::ShaderManager::GetVertexShader(graphic::SHADER_TYPE::DEBUG_PRIMITIVE_2D));
		pipelineStartupInfo2D.setPixelShader(graphic::ShaderManager::GetPixelShader(graphic::SHADER_TYPE::DEBUG_PRIMITIVE_2D));
		pipelineStartupInfo2D.setInputLayoutElement(0, graphic::types::SHADER_SEMANTIC_TYPE::POSITION, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo2D.setInputLayoutElement(1, graphic::types::SHADER_SEMANTIC_TYPE::COLOR, 0, graphic::types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT);
		pipelineStartupInfo2D.setInputLayoutCount(2);
		pipelineStartupInfo2D.setRenderTaretFormat(0, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
		pipelineStartupInfo2D.setRenderTaretCount(1);
		pipelineStartupInfo2D.setRootSignature(m_RootSignature2D);
		m_Pipeline2D.startup(graphic::System::GetDevice(), pipelineStartupInfo2D);

		m_VertexBufferList2D.resize(graphic::Config::GetBackBufferCount());
		graphic::BufferStartupInfo vertexBufferStartupInfo2D;
		vertexBufferStartupInfo2D.setBufferStartupInfo(sizeof(VertexInfo) * 0x10000);
		for (auto& vertexBuffer2D : m_VertexBufferList2D)vertexBuffer2D.startup(graphic::System::GetDevice(), vertexBufferStartupInfo2D);

		m_IndexBufferList2D.resize(graphic::Config::GetBackBufferCount());
		graphic::BufferStartupInfo indexBufferStartupInfo2D;
		indexBufferStartupInfo2D.setBufferStartupInfo(sizeof(u16) * 0x10000);
		for (auto& indexBuffer2D : m_IndexBufferList2D)indexBuffer2D.startup(graphic::System::GetDevice(), indexBufferStartupInfo2D);

		for (auto& vertices : m_VertexInfo2DLists)vertices.reserve(0x10000);
		for (auto& indices : m_Indices2DLists)indices.reserve(0x10000);

		m_CriticalSection.startup();
#endif // BUILD_DEBUG
	}

	// 破棄
	void Primitive2D::Cleanup()
	{
#if BUILD_DEBUG
		m_CriticalSection.cleanup();

		for (auto& vertices : m_VertexInfo2DLists)vertices.clear();
		for (auto& indices : m_Indices2DLists)indices.clear();
		for (auto& indexBuffer2D : m_IndexBufferList2D)indexBuffer2D.cleanup();
		m_IndexBufferList2D.clear();
		for (auto& vertexBuffer2D : m_VertexBufferList2D)vertexBuffer2D.cleanup();
		m_VertexBufferList2D.clear();
		m_Pipeline2D.cleanup();
		m_RootSignature2D.cleanup();
#endif // BUILD_DEBUG
	}

	// 更新
	void Primitive2D::Update()
	{
#if BUILD_DEBUG
#endif // BUILD_DEBUG
	}

	// 描画
	void Primitive2D::Draw()
	{
#if BUILD_DEBUG
		auto& vertexInfos2D = m_VertexInfo2DLists[core::System::GetDrawIndex()];
		auto& indices2D = m_Indices2DLists[core::System::GetDrawIndex()];
		if (vertexInfos2D.empty() || indices2D.empty())return;

		auto& vertexBuffer2D = m_VertexBufferList2D[graphic::System::GetBackBufferIndex()];
		auto& indexBuffer2D = m_IndexBufferList2D[graphic::System::GetBackBufferIndex()];

		vertexBuffer2D.store(reinterpret_cast<std::byte*>(vertexInfos2D.data()), vertexInfos2D.size() * sizeof(VertexInfo), 0);
		indexBuffer2D.store(reinterpret_cast<std::byte*>(indices2D.data()), indices2D.size() * sizeof(u16), 0);

		graphic::VertexBufferView vertexBufferView2D;
		vertexBufferView2D.startup(vertexBuffer2D, 0, static_cast<u32>(vertexInfos2D.size()), sizeof(VertexInfo));
		graphic::IndexBufferView indexBufferView2D;
		indexBufferView2D.startup(indexBuffer2D, 0, static_cast<u32>(indices2D.size()), sizeof(u16), graphic::types::GRAPHIC_FORMAT::R16_UINT);

		auto& commandList = RenderingManager::GetDebug2DCommandList();

		commandList.setRootSignature(m_RootSignature2D);
		commandList.setPipeline(m_Pipeline2D);
		commandList.setVertexBuffer(0, vertexBufferView2D);
		commandList.registVertexBuffers(1);
		commandList.setIndexBuffer(indexBufferView2D);
		commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		commandList.drawIndexedInstanced(static_cast<u32>(indices2D.size()), 1, 0, 0, 0);
		graphic::ResourceManager::Regist(vertexBuffer2D);
		graphic::ResourceManager::Regist(indexBuffer2D);
		vertexInfos2D.clear();
		indices2D.clear();
#endif // BUILD_DEBUG
	}

	// 2D三角形の描画登録
	void Primitive2D::AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Color _color)
	{
#if BUILD_DEBUG
		AddTriangle2D(_point1, _point2, _point3, _color, _color, _color);
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3,
		const Color _color1, const Color _color2, const Color _color3)
	{
#if BUILD_DEBUG
		AddTriangle2D({ VertexInfo{ _point1, _color1 }, VertexInfo{ _point2, _color2 }, VertexInfo{ _point3, _color3 } });
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddTriangle2D(const VertexInfo(&_vertices)[3])
	{
#if BUILD_DEBUG
		const u16 indices[] = { 0, 1, 2 };
		Add2D(_vertices, 3, indices, 3);
#endif // BUILD_DEBUG
	}

	// 2Dクアッドの描画登録
	void Primitive2D::AddQuad2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4, const Color _color)
	{
#if BUILD_DEBUG
		AddQuad2D(_point1, _point2, _point3, _point4, _color, _color, _color, _color);
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddQuad2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4,
		const Color _color1, const Color _color2, const Color _color3, const Color _color4)
	{
#if BUILD_DEBUG
		AddQuad2D({ 
			VertexInfo{ _point1, _color1 }, 
			VertexInfo{ _point2, _color2 }, 
			VertexInfo{ _point3, _color3 }, 
			VertexInfo{ _point4, _color4 } });
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddQuad2D(const VertexInfo(&_vertices)[4])
	{
#if BUILD_DEBUG
		const u16 indices[] = { 0, 1, 3, 1, 2, 3 };
		Add2D(_vertices, 4, indices, 6);
#endif // BUILD_DEBUG
	}

	// 2D矩形の描画登録
	void Primitive2D::AddRect2D(const Rect _rect, const Color _color)
	{
#if BUILD_DEBUG
		AddRect2D(_rect, _color, _color, _color, _color);
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddRect2D(const Rect _rect, const Color _color1, const Color _color2, const Color _color3, const Color _color4)
	{
#if BUILD_DEBUG
		const f32 left = _rect.m_X;
		const f32 right = _rect.m_X + _rect.m_Width;
		const f32 up = _rect.m_Y;
		const f32 down = _rect.m_Y + _rect.m_Height;
		const Vec4 leftUp = Vec4{ left,	up,		0.0f };
		const Vec4 rightUp = Vec4{ right,	up,		0.0f };
		const Vec4 leftDown = Vec4{ left,	down,	0.0f };
		const Vec4 rightDown = Vec4{ right,	down,	0.0f };
		AddRect2D({ VertexInfo{ leftUp, _color1 }, VertexInfo{ rightUp, _color2 },
			VertexInfo{ rightDown, _color3 }, VertexInfo{ leftDown, _color4 } });
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddRect2D(const VertexInfo(&_vertices)[4])
	{
#if BUILD_DEBUG
		const u16 indices[] = { 0, 1, 3, 1, 2, 3 };
		Add2D(_vertices, 4, indices, 6);
#endif // BUILD_DEBUG
	}

	// 2D線分の描画登録
	void Primitive2D::AddLine2D(const Vec4 _begin, const Vec4 _end, const f32 _width, const Color _color)
	{
#if BUILD_DEBUG
		const Vec4 dir = (_end - _begin);
		const Vec4 side = VecNormalize(VecCross(dir, FrontVector)) * (_width / -2.0f);
		const Vec4 beginRight = _begin + side;
		const Vec4 beginLeft = _begin - side;
		const Vec4 endRight = _end + side;
		const Vec4 endLeft = _end - side;
		AddLine2D({ VertexInfo{ beginRight, _color }, VertexInfo{ beginLeft, _color },
			VertexInfo{ endRight, _color }, VertexInfo{ endLeft, _color } });
#endif // BUILD_DEBUG
	}
	void Primitive2D::AddLine2D(const VertexInfo(&_vertices)[4])
	{
#if BUILD_DEBUG
		const u16 indices[] = { 0, 1, 2, 1, 3, 2 };
		Add2D(_vertices, 4, indices, 6);
#endif // BUILD_DEBUG
	}

	// 2Dの描画登録
	void Primitive2D::Add2D(const VertexInfo* const _vertices, const s32 _vertexCount, const u16* const _indices, const s32 _indexCount)
	{
#if BUILD_DEBUG
		auto& vertexInfos2D = m_VertexInfo2DLists[core::System::GetUpdateIndex()];
		auto& indices2D = m_Indices2DLists[core::System::GetUpdateIndex()];

		CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);

		if (vertexInfos2D.size() + _vertexCount >= 0x10000)
		{
			CANDY_LOG("頂点の上限を超えています");
			return;
		}
		if (indices2D.size() + _indexCount >= 0x10000)
		{
			CANDY_LOG("インデックスの上限を超えています");
			return;
		}

		for (s32 i = 0; i < _indexCount; ++i)
		{
			const u16 index = _indices[i] + static_cast<u16>(vertexInfos2D.size());
			indices2D.push_back(index);
		}
		for (s32 i = 0; i < _vertexCount; ++i)
		{
			VertexInfo v = _vertices[i];
			v.m_Pos = Utility::ToScreenPosFrom2DPos(v.m_Pos);
			vertexInfos2D.push_back(v);
		}
#endif // BUILD_DEBUG
	}
}

CANDY_APP_NAMESPACE_END
