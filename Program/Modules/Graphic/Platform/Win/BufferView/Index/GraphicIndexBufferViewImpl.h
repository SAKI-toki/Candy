#ifndef CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H
#define CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class BufferImpl;

	class IndexBufferViewImpl
	{
	protected:
		void startup(const BufferImpl& _buffer, const u64 _offset, const u32 _indexCount, 
			const u32 _byteStride, const types::GRAPHIC_FORMAT _graphicFormat);
		void cleanup();

	public:
		const D3D12_INDEX_BUFFER_VIEW& getIndexBufferView()const { return m_IndexBufferView; }
		const D3D12_INDEX_BUFFER_VIEW* getIndexBufferViewAddress()const { return &m_IndexBufferView; }

	private:
		D3D12_INDEX_BUFFER_VIEW m_IndexBufferView{};
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_INDEX_BUFFER_VIEW_IMPL_H
