/*****************************************************************//**
 * \file   GameFlow.h
 * \brief  �Q�[���t���[
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_GAME_FLOW_H
#define CANDY_GAME_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace GameFlow
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();
	// �`��
	void Draw();
}

CANDY_NAMESPACE_END

#endif // CANDY_GAME_FLOW_H
