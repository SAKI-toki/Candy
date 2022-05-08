#include "GraphicIndexBufferView.h"
#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void IndexBufferView::startup(const Buffer& _buffer, const u64 _offset, const u32 _indexCount, const u32 _byteStride, const GRAPHIC_FORMAT _graphicFormat)
	{
		IndexBufferViewImpl::startup(_buffer, _offset, _indexCount, _byteStride, _graphicFormat);
		m_IndexCount = _indexCount;
	}

	void IndexBufferView::cleanup()
	{
		IndexBufferViewImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
