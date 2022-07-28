#ifndef UI_H
#define UI_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace UI
{
	void Startup();
	void Cleanup();

	void Update();

	void Draw();
}

CANDY_APP_NAMESPACE_END

#endif // UI_H
