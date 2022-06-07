/*****************************************************************//**
 * \file   DebugDraw.h
 * \brief  �f�o�b�O�`��
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_DRAW_H
#define CANDY_DEBUG_DRAW_H

CANDY_NAMESPACE_BEGIN

namespace DebugDraw
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();
	// �`��
	void Draw();

	// ������o�^(�ʒu)
	void DrawString(const Vec4 _pos, const char* const _format, ...);
	// ������o�^(�ʒu, �F)
	void DrawString(const Vec4 _pos, const Color _color, const char* const _format, ...);
	// ������o�^(�ʒu, �F, �T�C�Y)
	void DrawString(const Vec4 _pos, const Color _color, const f32 _scale, const char* const _format, ...);
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_H
