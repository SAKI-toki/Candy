/*****************************************************************//**
 * \file   Input.h
 * \brief  ����
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_H
#define CANDY_INPUT_H

CANDY_NAMESPACE_BEGIN

namespace Input
{
	// ������
	void Startup();
	// �j��
	void Cleanup();
	// �X�V
	void Update();

	// �L�[���͊J�n����
	bool IsKeyTrigger(const u8 _key);
	// �L�[���͔���
	bool IsKeyOn(const u8 _key);
	// �L�[���͏I������
	bool IsKeyRelease(const u8 _key);
	// �L�[���͔���(���Ԋu)
	bool IsKeyRepeat(const u8 _key);

	// �}�E�X��PC��ʏ�̈ʒu�擾
	Vec4 GetScreenMousePos();
	// �}�E�X�̃A�v����ʏ�̈ʒu�擾
	Vec4 GetClientMousePos();
	// �}�E�X��PC��ʏ��1�t���O�ʒu�擾
	Vec4 GetPrevScreenMousePos();
	// �}�E�X�̃A�v����ʏ��1�t���O�ʒu�擾
	Vec4 GetPrevClientMousePos();
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_H
