#ifndef CANDY_GRAPHIC_SCISSOR_RECT_H
#define CANDY_GRAPHIC_SCISSOR_RECT_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/ScissorRect/GraphicScissorRectImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class ScissorRect : public ScissorRectImpl
	{
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_SCISSOR_RECT_H
