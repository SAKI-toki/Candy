#ifndef CANDY_GRAPHIC_H
#define CANDY_GRAPHIC_H

#include "GraphicDef.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void Startup();
	void Cleanup();
	void Update();
	void DrawBegin();
	void DrawEnd();
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_H
