/*****************************************************************//**
 * \file   InputMouse.h
 * \brief  �}�E�X����
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_MOUSE_H
#define CANDY_INPUT_MOUSE_H

#if PLATFORM_WIN
#include <Input/Platform/Win/Mouse/InputMouseImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Input
{
	class Mouse : public Impl::MouseImpl
	{
	public:
		// ������
		void startup();
		// �j��
		void cleanup();
		// �X�V
		void update();

		// ���Z�b�g
		void reset();

		// PC��ʏ�̈ʒu�擾
		Vec4 getScreenPos()const;
		// �A�v����ʏ�̈ʒu�擾
		Vec4 getClientPos()const;
		// PC��ʏ��1�t���O�ʒu�擾
		Vec4 getPrevScreenPos()const;
		// �A�v����ʏ��1�t���O�ʒu�擾
		Vec4 getPrevClientPos()const;

	private:
		Vec4 m_ScreenPos{};
		Vec4 m_ClientPos{};
		Vec4 m_PrevScreenPos{};
		Vec4 m_PrevClientPos{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_MOUSE_H
