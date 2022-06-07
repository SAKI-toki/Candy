/*****************************************************************//**
 * \file   Rect.h
 * \brief  ��`
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_RECT_H
#define CANDY_RECT_H

CANDY_NAMESPACE_BEGIN

struct alignas(16) Rect
{
	// �R���X�g���N�^
	Rect();
	Rect(const f32 _x, const f32 _y, const f32 _width, const f32 _height);

	// �T�C�Y��̃Z�b�g
	Rect& setSize(const f32 _x, const f32 _y, const f32 _width, const f32 _height);
	// ���W��̃Z�b�g
	Rect& setPos(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);

	// �E���W�̎擾
	f32 getRight()const;
	// �����W�̎擾
	f32 getBottom()const;

	f32 m_X;
	f32 m_Y;
	f32 m_Width;
	f32 m_Height;
};

CANDY_NAMESPACE_END

#include "Rect.inl"

#endif // CANDY_RECT_H
