/*****************************************************************//**
 * \file   DebugDrawString.h
 * \brief  ������̃f�o�b�O�`��
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_DRAW_STRING_H
#define CANDY_DEBUG_DRAW_STRING_H

CANDY_NAMESPACE_BEGIN

namespace DebugDraw::String
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();
	// �`��
	void Draw();
	
	// �`��o�^(�ʒu)
	void Add(const Vec4 _pos, const std::string& _str);
	// �`��o�^(�ʒu, �F)
	void Add(const Vec4 _pos, const Color _color, const std::string& _str);
	// �`��o�^(�ʒu, �F, �T�C�Y)
	void Add(const Vec4 _pos, const Color _color, const f32 _scale, const std::string& _str);
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_DRAW_STRING_H
