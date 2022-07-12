#ifndef CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_H
#define CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/BufferView/Vertex/GraphicVertexBufferViewImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Buffer;

class VertexBufferView : public impl::VertexBufferViewImpl
{
public:
	void startup(const Buffer& _buffer, const u64 _offset, const u32 _vertexCount, const u32 _byteStride);
	void cleanup();

	u32 getVertexCount()const { return m_VertexCount; }

private:
	u32 m_VertexCount{};
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_H
