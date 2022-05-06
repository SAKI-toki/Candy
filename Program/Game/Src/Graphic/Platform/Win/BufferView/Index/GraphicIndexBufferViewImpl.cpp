#include "GraphicIndexBufferViewImpl.h"
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void IndexBufferViewImpl::startup(const BufferImpl& _buffer, const u64 _offset, const u32 _size, const GRAPHIC_FORMAT _graphicFormat)
	{
		m_IndexBufferView.BufferLocation = _buffer.getGpuVirtualAddress() + _offset;
		m_IndexBufferView.SizeInBytes = _size;
		m_IndexBufferView.Format = ConvGraphicFormat(_graphicFormat);
	}

	void IndexBufferViewImpl::cleanup()
	{
		m_IndexBufferView.BufferLocation = 0;
		m_IndexBufferView.SizeInBytes = 0;
		m_IndexBufferView.Format = ConvGraphicFormat(GRAPHIC_FORMAT::UNKNOWN);
	}
}

CANDY_NAMESPACE_END
