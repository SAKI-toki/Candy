/*****************************************************************//**
 * \file   FileSystem.h
 * \brief  �t�@�C���V�X�e��
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_H
#define CANDY_FILE_SYSTEM_H

#include "Work/FileSystemWork.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// ������
	void Startup();
	// �X�V
	void Cleanup();

	// �t�@�C���T�C�Y�̎擾
	u64 GetFileSize(const std::string& _path);
	// �ǂݍ��݃��N�G�X�g
	WorkHandle RequestRead(const std::string& _path, std::byte* const _buf, u64 _bufSize);
	// �ǂݍ��݃��N�G�X�g(����)
	bool RequestReadNoWait(const std::string& _path, std::byte* const _buf, u64 _bufSize);
	// �t�@�C���ǂݍ��ݏI������
	bool IsEndReadWork(const WorkHandle _handle);
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_H
