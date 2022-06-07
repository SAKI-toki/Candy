/*****************************************************************//**
 * \file   FileSystemFileInfoImpl.h
 * \brief  �t�@�C���V�X�e���̃t�@�C�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
#define CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileInfoImpl
	{
	protected:
		// �}�E���g
		bool mount(const std::string& _path);

		// �t�@�C�������
		void close();
		
		// �t�@�C���T�C�Y�̎擾
		u64 getSize()const;

	public:
		// �t�@�C���n���h���̎擾
		HANDLE getHandle()const;

	private:
		HANDLE m_FileHandle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
