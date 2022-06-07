/*****************************************************************//**
 * \file   SceneFlow.h
 * \brief  �V�[���t���[
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_SCENE_FLOW_H
#define CANDY_SCENE_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace SceneFlow
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();
}

CANDY_NAMESPACE_END

#endif // CANDY_SCENE_FLOW_H
