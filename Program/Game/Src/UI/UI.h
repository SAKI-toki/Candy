#ifndef CANDY_UI_H
#define CANDY_UI_H

#include <Graphic/CommandList/GraphicCommandList.h>

CANDY_NAMESPACE_BEGIN

namespace UI
{
	void Startup();
	void Cleanup();

	void Update();

	void Draw();
}

CANDY_NAMESPACE_END

#endif // CANDY_UI_H
