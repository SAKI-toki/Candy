/*****************************************************************//**
 * \file   FileSystemFileInfo.cpp
 * \brief  ファイルシステムのファイル情報
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileInfo.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void FileInfo::startup(const std::string_view _path)
	{
		FileInfoImpl::mount(_path);
		m_Path = Path::FormatPath(_path);
		m_Hash = Fnv::Hash32Low(m_Path);
		m_Size = FileInfoImpl::getSize();
	}

	// 破棄
	void FileInfo::cleanup()
	{
		FileInfoImpl::close();
	}

	// ファイルサイズの取得
	u64 FileInfo::getSize()const
	{
		return m_Size;
	}

	// ハッシュの取得
	u64 FileInfo::getHash()const
	{
		return m_Hash;
	}

	// 比較関数群
	bool FileInfo::operator==(const FileInfo& _other)const { return m_Hash == _other.m_Hash; }
	bool FileInfo::operator!=(const FileInfo& _other)const { return !(*this == _other); }
	bool FileInfo::operator==(const u32 _hash)const { return m_Hash == _hash; }
	bool FileInfo::operator!=(const u32 _hash)const { return !(*this == _hash); }
	bool FileInfo::operator==(const std::string_view _path)const { return m_Hash == Fnv::Hash32Low(Path::FormatPath(_path)); }
	bool FileInfo::operator!=(const std::string_view _path)const { return !(*this == _path); }
}

CANDY_CORE_NAMESPACE_END
