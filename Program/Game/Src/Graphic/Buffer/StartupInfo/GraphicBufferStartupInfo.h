#ifndef CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H
#define CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Buffer/StartupInfo/GraphicBufferStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class BufferStartupInfo : public BufferStartupInfoImpl
	{
	public:
		void setBufferStartupInfo(const u64 _size);
		void setRenderTargetStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_STARTUP_INFO_H
