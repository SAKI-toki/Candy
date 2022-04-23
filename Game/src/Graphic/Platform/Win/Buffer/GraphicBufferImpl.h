#ifndef CANDY_GRAPHIC_BUFFER_IMPL_H
#define CANDY_GRAPHIC_BUFFER_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class BufferImpl
	{
	public:
		void startupRenderTarget(ID3D12Device* const _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height);
		void cleanup();

		ID3D12Resource* getBuffer()const { return m_Buffer.Get(); }
		ID3D12Resource** getBufferAddress() { return m_Buffer.GetAddressOf(); }

	private:
		ComPtr<ID3D12Resource> m_Buffer;
		D3D12_RESOURCE_STATES m_ResourceState;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_IMPL_H
