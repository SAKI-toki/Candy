/*****************************************************************//**
 * \file   FileSystemFileEnumerator.cpp
 * \brief  �t�@�C���V�X�e���̃t�@�C����
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileEnumerator.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// ������
	void FileEnumerator::startup(const std::string& _basePath)
	{
		FileEnumeratorImpl::startup(_basePath);
	}

	// ���̃t�@�C����
	bool FileEnumerator::next()
	{
		return FileEnumeratorImpl::next();
	}

	// �f�B���N�g���[��
	bool FileEnumerator::isDirectory()const
	{
		return FileEnumeratorImpl::isDirectory();
	}

	// �p�X�擾
	std::string FileEnumerator::getPath()const
	{
		return FileEnumeratorImpl::getPath();
	}
}

CANDY_NAMESPACE_END
