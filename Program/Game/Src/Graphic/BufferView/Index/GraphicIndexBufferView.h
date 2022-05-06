#ifndef CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H
#define CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/BufferView/Index/GraphicIndexBufferViewImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Buffer;

	class IndexBufferView : public IndexBufferViewImpl
	{
	public:
		void startup(const Buffer& _buffer, const u64 _offset, const u32 _size, const GRAPHIC_FORMAT _graphicFormat);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_INDEX_BUFFER_VIEW_H
