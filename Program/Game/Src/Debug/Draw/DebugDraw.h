#ifndef CANDY_DEBUG_DRAW_H
#define CANDY_DEBUG_DRAW_H

CANDY_NAMESPACE_BEGIN

namespace DebugDraw
{
	void Startup();
	void Cleanup();

	void Update();
	void Draw();

	void DrawString(const Vec4 _pos, const char* const _format, ...);
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_H
