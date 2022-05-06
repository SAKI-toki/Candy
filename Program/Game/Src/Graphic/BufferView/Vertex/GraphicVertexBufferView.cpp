#include "GraphicVertexBufferView.h"
#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void VertexBufferView::startup(const Buffer& _buffer, const u64 _offset, const u32 _size, const u32 _byteStride)
	{
		VertexBufferViewImpl::startup(_buffer, _offset, _size, _byteStride);
	}

	void VertexBufferView::cleanup()
	{
		VertexBufferViewImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
