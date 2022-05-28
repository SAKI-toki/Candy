#ifndef CANDY_FONT_H
#define CANDY_FONT_H

#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

enum FONT_TYPE
{
	GOTHIC,
	MINCHO,
	SIZE,
};
inline constexpr const char* const FontFileNames[] =
{
	"msgothic",
	"msmincho",
};
static_assert((s32)FONT_TYPE::SIZE == GetArraySize(FontFileNames));

namespace Font
{
	void Startup();
	void Cleanup();

	Graphic::Buffer& GetFontTextureBuffer(const FONT_TYPE _fontType);
	Rect GetFontUv(const FONT_TYPE _fontType, const u32 _c);
}

CANDY_NAMESPACE_END

#endif // CANDY_FONT_H
