#include "GraphicBufferImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void BufferImpl::startupRenderTarget(ID3D12Device* const _device, const TEXTURE_FORMAT _textureFormat, const s32 _width, const s32 _height)
	{
		D3D12_HEAP_PROPERTIES prop{};
		prop.Type = D3D12_HEAP_TYPE_DEFAULT;

		D3D12_RESOURCE_DESC desc{};
		desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		desc.Format = ConvTextureFormat(_textureFormat);
		desc.Width = _width;
		desc.Height = _height;
		desc.DepthOrArraySize = 1;
		desc.SampleDesc.Count = 1;
		desc.MipLevels = 1;
		desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;

		D3D12_CLEAR_VALUE clearValue;
		clearValue.Format = desc.Format;
		clearValue.Color[0] = clearValue.Color[1] = clearValue.Color[2] = clearValue.Color[3] = 0.0f;

		m_ResourceState = D3D12_RESOURCE_STATE_COMMON;

		CANDY_ASSERT_HRESULT(_device->CreateCommittedResource(&prop, D3D12_HEAP_FLAG_NONE, &desc,
			m_ResourceState, &clearValue, IID_PPV_ARGS(m_Buffer.GetAddressOf())));
	}

	void BufferImpl::cleanup()
	{
		m_Buffer.Reset();
	}
}

CANDY_NAMESPACE_END
