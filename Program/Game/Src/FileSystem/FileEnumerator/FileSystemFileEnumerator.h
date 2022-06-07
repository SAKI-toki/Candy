/*****************************************************************//**
 * \file   FileSystemFileEnumerator.h
 * \brief  �t�@�C���V�X�e���̃t�@�C����
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
#define CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H

#if PLATFORM_WIN
#include <FileSystem/Platform/Win/FileEnumerator/FileSystemFileEnumeratorImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// �t�@�C����
	class FileEnumerator : public FileEnumeratorImpl
	{
	public:
		// ������
		void startup(const std::string& _basePath);

		// ���̃t�@�C����
		bool next();
		// �f�B���N�g���[��
		bool isDirectory()const;

		// �p�X�擾
		std::string getPath()const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
