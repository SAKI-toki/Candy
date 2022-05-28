#ifndef CANDY_DEBUG_DRAW_STRING_H
#define CANDY_DEBUG_DRAW_STRING_H

CANDY_NAMESPACE_BEGIN

namespace DebugDraw::String
{
	void Startup();
	void Cleanup();

	void Update();
	void Draw();

	void Add(const Vec4 _pos, const std::string& _str);
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_STRING_H
