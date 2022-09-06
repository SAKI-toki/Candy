#include "GraphicBufferStartupInfoImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	void BufferStartupInfoImpl::setBufferStartupInfo(const u64 _size)
	{
		reset();

		m_HeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;

		m_ResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
		m_ResourceDesc.Format = ConvGraphicFormat(types::GRAPHIC_FORMAT::UNKNOWN);
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

	void BufferStartupInfoImpl::setRenderTargetStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, 
		const u64 _width, const u64 _height, const Color& _clearColor)
	{
		reset();

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
		m_ClearValue.Color[0] = _clearColor.x;
		m_ClearValue.Color[1] = _clearColor.y;
		m_ClearValue.Color[2] = _clearColor.z;
		m_ClearValue.Color[3] = _clearColor.w;
		m_UseClearValue = true;
	}

	void BufferStartupInfoImpl::setDepthStencilStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		reset();

		const auto graphicFormat = ConvGraphicFormat(_graphicFormat);

		m_HeapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;

		m_ResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		m_ResourceDesc.Format = graphicFormat;
		m_ResourceDesc.Width = _width;
		m_ResourceDesc.Height = static_cast<u32>(_height);
		m_ResourceDesc.DepthOrArraySize = 1;
		m_ResourceDesc.SampleDesc.Count = 1;
		m_ResourceDesc.MipLevels = 1;
		m_ResourceDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

		m_ClearValue.Format = graphicFormat;
		m_ClearValue.DepthStencil.Depth = 1.0f;
		m_ClearValue.DepthStencil.Stencil = 0;
		m_UseClearValue = true;

		m_InitState = D3D12_RESOURCE_STATE_DEPTH_WRITE;
	}

	void BufferStartupInfoImpl::setTextureStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		reset();

		const auto graphicFormat = ConvGraphicFormat(_graphicFormat);

		m_HeapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;

		m_ResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		m_ResourceDesc.Format = graphicFormat;
		m_ResourceDesc.Width = _width;
		m_ResourceDesc.Height = static_cast<UINT>(_height);
		m_ResourceDesc.DepthOrArraySize = 1;
		m_ResourceDesc.SampleDesc.Count = 1;
		m_ResourceDesc.MipLevels = 1;
		m_ResourceDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

		m_UseClearValue = false;

		m_InitState = D3D12_RESOURCE_STATE_COPY_DEST;
	}

	void BufferStartupInfoImpl::reset()
	{
		m_HeapProperties = D3D12_HEAP_PROPERTIES{};
		m_ResourceDesc = D3D12_RESOURCE_DESC{};
		m_ClearValue = D3D12_CLEAR_VALUE{};
		m_InitState = D3D12_RESOURCE_STATE_COMMON;
		m_UseClearValue = false;
	}

	void BufferStartupInfoImpl::setInitBarrierState(const types::BARRIER_STATE _barrierState)
	{
		m_InitState = ConvBarrierState(_barrierState);
	}
}

CANDY_GRAPHIC_NAMESPACE_END
