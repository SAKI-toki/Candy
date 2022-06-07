/*****************************************************************//**
 * \file   FileSystemFileInfo.cpp
 * \brief  �t�@�C���V�X�e���̃t�@�C�����
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileInfo.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// ������
	void FileInfo::startup(const std::string& _path)
	{
		FileInfoImpl::mount(_path);
		m_Path = Path::FormatPath(_path);
		m_Hash = Fnv::Hash32Low(m_Path);
		m_Size = FileInfoImpl::getSize();
	}

	// �j��
	void FileInfo::cleanup()
	{
		FileInfoImpl::close();
	}

	// �t�@�C���T�C�Y�̎擾
	u64 FileInfo::getSize()const
	{
		return m_Size;
	}

	// �n�b�V���̎擾
	u64 FileInfo::getHash()const
	{
		return m_Hash;
	}

	// ��r�֐��Q
	bool FileInfo::operator==(const FileInfo& _other)const { return m_Hash == _other.m_Hash; }
	bool FileInfo::operator!=(const FileInfo& _other)const { return !(*this == _other); }
	bool FileInfo::operator==(const u32 _hash)const { return m_Hash == _hash; }
	bool FileInfo::operator!=(const u32 _hash)const { return !(*this == _hash); }
	bool FileInfo::operator==(const std::string& _path)const { return m_Hash == Fnv::Hash32Low(Path::FormatPath(_path)); }
	bool FileInfo::operator!=(const std::string& _path)const { return !(*this == _path); }
}

CANDY_NAMESPACE_END
