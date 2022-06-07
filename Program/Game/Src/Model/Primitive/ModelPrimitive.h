/*****************************************************************//**
 * \file   ModelPrimitive.h
 * \brief  ÉvÉäÉ~ÉeÉBÉuÉÇÉfÉã
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_MODEL_PRIMITIVE_H
#define CANDY_MODEL_PRIMITIVE_H

#include <Graphic/CommandList/GraphicCommandList.h>

CANDY_NAMESPACE_BEGIN

namespace Model::Primitive
{
	struct VertexInfo
	{
		VertexInfo() = default;
		VertexInfo(const Vec4 _pos, const Color _color) :m_Position{ _pos }, m_Color{ _color } {}
		Vec4 m_Position;
		Color m_Color;
	};

	// èâä˙âª
	void Startup();
	// îjä¸
	void Cleanup();
	// ï`âÊ
	void Draw(Graphic::CommandList& _commandList);

	// 2DéOäpå`ÇÃï`âÊìoò^
	void AddTriangle2D(const Vec4 _pos, const Color _color);
	void AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Color _color);
	void AddTriangle2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3,
		const Color _color1, const Color _color2, const Color _color3);
	void AddTriangle2D(const VertexInfo(&_vertices)[3]);

	// 2DãÈå`ÇÃï`âÊìoò^
	void AddRect2D(const Vec4 _pos, const Color _color);
	void AddRect2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4, const Color _color);
	void AddRect2D(const Vec4 _point1, const Vec4 _point2, const Vec4 _point3, const Vec4 _point4,
		const Color _color1, const Color _color2, const Color _color3, const Color _color4);
	void AddRect2D(const Rect _rect, const Color _color);
	void AddRect2D(const Rect _rect, const Color _color1, const Color _color2, const Color _color3, const Color _color4);
	void AddRect2D(const VertexInfo(&_vertices)[4]);

	// 2DÇÃï`âÊìoò^
	void Add2D(const VertexInfo* const _vertices, const s32 _vertexCount, const u16* const _indices, const s32 _indexCount);
}

CANDY_NAMESPACE_END

#endif // CANDY_MODEL_PRIMITIVE_H
