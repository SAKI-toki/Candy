#include "GraphicBufferStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void BufferStartupInfoImpl::setBufferStartupInfo(const u64 _size)
	{
		m_HeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;

		m_ResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
		m_ResourceDesc.Format = ConvGraphicFormat(GRAPHIC_FORMAT::UNKNOWN);
		m_ResourceDesc.Width = _size;
		m_ResourceDesc.Height = 1;
		m_ResourceDesc.DepthOrArraySize = 1;
		m_ResourceDesc.SampleDesc.Count = 1;
		m_ResourceDesc.MipLevels = 1;
		m_ResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
		m_ResourceDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

		m_UseClearValue = false;

		m_InitState = D3D12_RESOURCE_STATE_GENERIC_READ;
	}

	void BufferStartupInfoImpl::setRenderTargetStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		const auto graphicFormat = ConvGraphicFormat(_graphicFormat);

		m_HeapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;

		m_ResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		m_ResourceDesc.Format = graphicFormat;
		m_ResourceDesc.Width = _width;
		m_ResourceDesc.Height = static_cast<UINT>(_height);
		m_ResourceDesc.DepthOrArraySize = 1;
		m_ResourceDesc.SampleDesc.Count = 1;
		m_ResourceDesc.MipLevels = 1;
		m_ResourceDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;

		m_ClearValue.Format = graphicFormat;
		m_ClearValue.Color[0] = m_ClearValue.Color[1] = m_ClearValue.Color[2] = m_ClearValue.Color[3] = 0.0f;
		m_UseClearValue = true;
	}
}

CANDY_NAMESPACE_END
