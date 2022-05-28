#ifndef CANDY_DEBUG_H
#define CANDY_DEBUG_H

CANDY_NAMESPACE_BEGIN

namespace Debug
{
	void Startup();
	void Cleanup();

	void Update();
	void Draw();
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_H
