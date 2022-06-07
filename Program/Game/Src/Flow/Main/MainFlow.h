/*****************************************************************//**
 * \file   MainFlow.h
 * \brief  ���C���t���[
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_MAIN_FLOW_H
#define CANDY_MAIN_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();

	// �I������
	bool IsEnd();
}

CANDY_NAMESPACE_END

#endif // CANDY_MAIN_FLOW_H
