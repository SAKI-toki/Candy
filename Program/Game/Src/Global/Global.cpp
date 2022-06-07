/*****************************************************************//**
 * \file   Global.cpp
 * \brief  �O���[�o���ȃp�����[�^�Q
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Global.h"
#include "Time/Time.h"

CANDY_NAMESPACE_BEGIN

namespace Global
{
	Tick m_PrevFrameTick;
	f32 m_AppTime = 0.0f;
	f32 m_AppTimeAll = 0.0f;
}

// ������
void Global::Startup()
{
	Time::Startup();
}

// �j��
void Global::Cleanup()
{
	Time::Cleanup();
}

// �X�V
void Global::Update()
{
	const auto tick = Time::GetTick();
	m_AppTime = Min((tick - m_PrevFrameTick).toSec(), Setting::GetMaxAppTime());
	m_PrevFrameTick = tick;
	m_AppTimeAll += m_AppTime;
}

// �O�t���[���̌o�ߎ��Ԃ̎擾
f32 Global::GetAppTime()
{
	return m_AppTime;
}

// �g�[�^���̃t���[���̌o�ߎ��Ԃ̎擾
f32 Global::GetAppTimeAll()
{
	return m_AppTimeAll;
}

CANDY_NAMESPACE_END
