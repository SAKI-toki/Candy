#ifndef CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H
#define CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/BufferView/Index/GraphicIndexBufferViewImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Buffer;

class IndexBufferView : public impl::IndexBufferViewImpl
{
public:
	void startup(const Buffer& _buffer, const u64 _offset, const u32 _indexCount, 
		const u32 _byteStride, const types::GRAPHIC_FORMAT _graphicFormat);
	void cleanup();

	u32 getIndexCount()const { return m_IndexCount; }

private:
	u32 m_IndexCount{};
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H
