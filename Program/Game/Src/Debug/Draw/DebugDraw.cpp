#include "DebugDraw.h"
#include "String/DebugDrawString.h"

CANDY_NAMESPACE_BEGIN

namespace DebugDraw
{
#if BUILD_DEBUG
#endif // BUILD_DEBUG
}

void DebugDraw::Startup()
{
#if BUILD_DEBUG
	DebugDraw::String::Startup();
#endif // BUILD_DEBUG
}

void DebugDraw::Cleanup()
{
#if BUILD_DEBUG
	DebugDraw::String::Cleanup();
#endif // BUILD_DEBUG
}

void DebugDraw::Update()
{
#if BUILD_DEBUG
	DebugDraw::String::Update();
#endif // BUILD_DEBUG
}

void DebugDraw::Draw()
{
#if BUILD_DEBUG
	DebugDraw::String::Draw();
#endif // BUILD_DEBUG
}

void DebugDraw::DrawString(const Vec4 _pos, const char* const _format, ...)
{
#if BUILD_DEBUG
	char str[2048];
	va_list args;
	va_start(args, _format);
	vsprintf_s(str, _format, args);
	va_end(args);
	String::Add(_pos, std::string{ str });
#else // BUILD_DEBUG
	CANDY_UNUSED_VALUE(_pos);
	CANDY_UNUSED_VALUE(_format);
#endif // BUILD_DEBUG
}

CANDY_NAMESPACE_END
