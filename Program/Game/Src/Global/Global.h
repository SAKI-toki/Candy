/*****************************************************************//**
 * \file   Global.h
 * \brief  �O���[�o���ȃp�����[�^�Q
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_GLOBAL_H
#define CANDY_GLOBAL_H

CANDY_NAMESPACE_BEGIN

namespace Global
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();

	// �O�t���[���̌o�ߎ��Ԃ̎擾
	f32 GetAppTime();
	// �g�[�^���̃t���[���̌o�ߎ��Ԃ̎擾
	f32 GetAppTimeAll();
}

CANDY_NAMESPACE_END

#endif // CANDY_GLOBAL_H
