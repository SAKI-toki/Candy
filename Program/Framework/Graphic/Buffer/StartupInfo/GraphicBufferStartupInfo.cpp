#include "GraphicBufferStartupInfo.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void BufferStartupInfo::setBufferStartupInfo( const u64 _size)
	{
		BufferStartupInfoImpl::setBufferStartupInfo(_size);
	}

	void BufferStartupInfo::setRenderTargetStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		BufferStartupInfoImpl::setRenderTargetStartupInfo(_graphicFormat, _width, _height);
	}

	void BufferStartupInfo::setDepthStencilStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		BufferStartupInfoImpl::setDepthStencilStartupInfo(_graphicFormat, _width, _height);
	}

	void BufferStartupInfo::setTextureStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
	{
		BufferStartupInfoImpl::setTextureStartupInfo(_graphicFormat, _width, _height);
	}
}

CANDY_NAMESPACE_END
