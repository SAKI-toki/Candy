/*****************************************************************//**
 * \file   Debug.h
 * \brief  �f�o�b�O�֘A
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_H
#define CANDY_DEBUG_H

CANDY_NAMESPACE_BEGIN

namespace Debug
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

#endif // CANDY_DEBUG_H
