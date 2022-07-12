#ifndef CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H
#define CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/StartupInfo/GraphicBufferStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class BufferStartupInfo : public impl::BufferStartupInfoImpl
{
public:
	void setBufferStartupInfo(const u64 _size);
	void setRenderTargetStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);
	void setDepthStencilStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);
	void setTextureStartupInfo(const types::GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H
