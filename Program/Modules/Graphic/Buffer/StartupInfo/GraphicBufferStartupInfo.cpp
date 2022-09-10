#include "GraphicBufferStartupInfo.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

void BufferStartupInfo::setBufferStartupInfo(const u64 _size)
{
	BufferStartupInfoImpl::setBufferStartupInfo(_size);
}

void BufferStartupInfo::setRenderTargetStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height, const Color& _clearColor)
{
	BufferStartupInfoImpl::setRenderTargetStartupInfo(_graphicFormat, _width, _height, _clearColor);
}

void BufferStartupInfo::setDepthStencilStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height)
{
	BufferStartupInfoImpl::setDepthStencilStartupInfo(_graphicFormat, _width, _height);
}

void BufferStartupInfo::setTextureStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height, const s32 _mipMapCount)
{
	BufferStartupInfoImpl::setTextureStartupInfo(_graphicFormat, _width, _height, _mipMapCount);
}

void BufferStartupInfo::setInitBarrierState(const types::BARRIER_STATE _barrierState)
{
	BufferStartupInfoImpl::setInitBarrierState(_barrierState);
}

CANDY_GRAPHIC_NAMESPACE_END
