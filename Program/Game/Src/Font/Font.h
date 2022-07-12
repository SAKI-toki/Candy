/*****************************************************************//**
 * \file   Font.h
 * \brief  フォント
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef FONT_H
#define FONT_H

#include <GameInclude.h>

#include <Graphic/Buffer/GraphicBuffer.h>

enum class FONT_TYPE
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
static_assert((s32)FONT_TYPE::SIZE == core::GetArraySize(FontFileNames));

namespace Font
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();

	// フォントテクスチャバッファの取得
	graphic::Buffer& GetFontTextureBuffer(const FONT_TYPE _fontType);
	// フォントのUVの取得
	Rect GetFontUv(const FONT_TYPE _fontType, const u32 _c);
}

#endif // FONT_H
