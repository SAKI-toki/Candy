#ifndef CANDY_GRAPHIC_VIEWPORT_H
#define CANDY_GRAPHIC_VIEWPORT_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Viewport/GraphicViewportImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Viewport : public ViewportImpl
	{
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_VIEWPORT_H
