#include "GraphicIndexBufferView.h"
#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void IndexBufferView::startup(const Buffer& _buffer, const u64 _offset, const u32 _size, const GRAPHIC_FORMAT _graphicFormat)
	{
		IndexBufferViewImpl::startup(_buffer, _offset, _size, _graphicFormat);
	}

	void IndexBufferView::cleanup()
	{
		IndexBufferViewImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
