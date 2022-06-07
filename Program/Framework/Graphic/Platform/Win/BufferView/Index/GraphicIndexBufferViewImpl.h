#ifndef CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H
#define CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class BufferImpl;

	class IndexBufferViewImpl
	{
	protected:
		void startup(const BufferImpl& _buffer, const u64 _offset, const u32 _indexCount, const u32 _byteStride, const GRAPHIC_FORMAT _graphicFormat);
		void cleanup();

	public:
		const D3D12_INDEX_BUFFER_VIEW& getIndexBufferView()const { return m_IndexBufferView; }
		const D3D12_INDEX_BUFFER_VIEW* getIndexBufferViewAddress()const { return &m_IndexBufferView; }

	private:
		D3D12_INDEX_BUFFER_VIEW m_IndexBufferView{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H
