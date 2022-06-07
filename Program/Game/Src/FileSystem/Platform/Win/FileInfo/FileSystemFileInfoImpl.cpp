/*****************************************************************//**
 * \file   FileSystemFileInfoImpl.cpp
 * \brief  �t�@�C���V�X�e���̃t�@�C�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// �}�E���g
	bool FileInfoImpl::mount(const std::string& _path)
	{
		m_FileHandle = ::CreateFile(_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
			nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		return m_FileHandle != INVALID_HANDLE_VALUE;
	}

	// �t�@�C�������
	void FileInfoImpl::close()
	{
		::CloseHandle(m_FileHandle);
	}

	// �t�@�C���T�C�Y�̎擾
	u64 FileInfoImpl::getSize()const
	{
		return static_cast<u64>(::GetFileSize(m_FileHandle, nullptr));
	}

	// �t�@�C���n���h���̎擾
	HANDLE FileInfoImpl::getHandle()const
	{
		return m_FileHandle;
	}
}

CANDY_NAMESPACE_END
