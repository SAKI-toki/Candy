/*****************************************************************//**
 * \file   InputMouse.cpp
 * \brief  �}�E�X����
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputMouse.h"

CANDY_NAMESPACE_BEGIN

namespace Input
{
	// ������
	void Mouse::startup()
	{
		reset();
	}

	// �j��
	void Mouse::cleanup()
	{

	}

	// �X�V
	void Mouse::update()
	{
		m_PrevScreenPos = m_ScreenPos;
		m_PrevClientPos = m_ClientPos;

		m_ScreenPos = MouseImpl::getScreenPos();
		m_ClientPos = MouseImpl::toClientPos(m_ScreenPos);
	}

	// ���Z�b�g
	void Mouse::reset()
	{
		m_ScreenPos = ZeroVector;
		m_ClientPos = ZeroVector;
		m_PrevScreenPos = ZeroVector;
		m_PrevClientPos = ZeroVector;
	}

	// PC��ʏ�̈ʒu�擾
	Vec4 Mouse::getScreenPos()const		{ return m_ScreenPos; }
	// �A�v����ʏ�̈ʒu�擾
	Vec4 Mouse::getClientPos()const		{ return m_ClientPos; }
	// PC��ʏ��1�t���O�ʒu�擾
	Vec4 Mouse::getPrevScreenPos()const { return m_PrevScreenPos; }
	// �A�v����ʏ��1�t���O�ʒu�擾
	Vec4 Mouse::getPrevClientPos()const { return m_PrevClientPos; }
}

CANDY_NAMESPACE_END
