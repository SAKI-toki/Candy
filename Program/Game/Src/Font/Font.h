/*****************************************************************//**
 * \file   Font.h
 * \brief  �t�H���g
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

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
	// ������
	void Startup();
	// �j��
	void Cleanup();

	// �t�H���g�e�N�X�`���o�b�t�@�̎擾
	Graphic::Buffer& GetFontTextureBuffer(const FONT_TYPE _fontType);
	// �t�H���g��UV�̎擾
	Rect GetFontUv(const FONT_TYPE _fontType, const u32 _c);
}

CANDY_NAMESPACE_END

#endif // CANDY_FONT_H
