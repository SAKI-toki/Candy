#include "GraphicVertexBufferViewImpl.h"
#include <Graphic/Platform/Win/Buffer/GraphicBufferImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void VertexBufferViewImpl::startup(const BufferImpl& _buffer, const u64 _offset, const u32 _size, const u32 _byteStride)
	{
		m_VertexBufferView.BufferLocation = _buffer.getGpuVirtualAddress() + _offset;
		m_VertexBufferView.SizeInBytes = _size;
		m_VertexBufferView.StrideInBytes = _byteStride;
	}

	void VertexBufferViewImpl::cleanup()
	{
		m_VertexBufferView.BufferLocation = 0;
		m_VertexBufferView.SizeInBytes = 0;
		m_VertexBufferView.StrideInBytes = 0;
	}
}

CANDY_NAMESPACE_END
