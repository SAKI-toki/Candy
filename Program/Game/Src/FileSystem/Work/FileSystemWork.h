/*****************************************************************//**
 * \file   FileSystemWork.h
 * \brief  �t�@�C���V�X�e���̃��[�N
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_WORK_H
#define CANDY_FILE_SYSTEM_WORK_H

#include "FileSystemWorkHandle.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work
	{
	public:
		// ������
		void startup(const u32 _hash, std::byte* const _buf);
		// �j��
		void cleanup();

		// ���[�N�n���h���̎擾
		WorkHandle getHandle()const;
		// �n�b�V���̎擾
		u32 getHash()const;
		// �o�b�t�@�̎擾
		std::byte* getBuffer()const;

		// �n���h���̃Z�b�g
		void setHandle(const WorkHandle _handle);

	private:
		WorkHandle m_Handle{};
		u32 m_Hash{};
		std::byte* m_Buffer = nullptr;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_WORK_H
