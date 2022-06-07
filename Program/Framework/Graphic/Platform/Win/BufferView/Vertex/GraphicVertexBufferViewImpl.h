#ifndef CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_IMPL_H
#define CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class BufferImpl;

	class VertexBufferViewImpl
	{
	protected:
		void startup(const BufferImpl& _buffer, const u64 _offset, const u32 _vertexCount, const u32 _byteStride);
		void cleanup();

	public:
		const D3D12_VERTEX_BUFFER_VIEW& getVertexBufferView()const { return m_VertexBufferView; }
		const D3D12_VERTEX_BUFFER_VIEW* getVertexBufferViewAddress()const { return &m_VertexBufferView; }

	private:
		D3D12_VERTEX_BUFFER_VIEW m_VertexBufferView{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_VERTEX_BUFFER_VIEW_IMPL_H
