/*****************************************************************//**
 * \file   FileSystemFileInfo.h
 * \brief  ファイルシステムのファイル情報
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_FILE_INFO_H
#define CANDY_FILE_SYSTEM_FILE_INFO_H

#if PLATFORM_WIN
#include <FileSystem/Platform/Win/FileInfo/FileSystemFIleInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileInfo : public FileInfoImpl
	{
	public:
		// 初期化
		void startup(const std::string& _path);
		// 破棄
		void cleanup();

		// ファイルサイズの取得
		u64 getSize()const;
		// ハッシュの取得
		u64 getHash()const;

		// 比較関数群
		bool operator==(const FileInfo& _other)const;
		bool operator!=(const FileInfo& _other)const;
		bool operator==(const u32 _hash)const;
		bool operator!=(const u32 _hash)const;
		bool operator==(const std::string& _path)const;
		bool operator!=(const std::string& _path)const;

	private:
		std::string m_Path;
		u32 m_Hash;
		u64 m_Size;
	};
}

CANDY_NAMESPACE_END

template<>
struct std::hash<CANDY_NAMESPACE_NAME::FileSystem::FileInfo>
{
	size_t operator()(const CANDY_NAMESPACE_NAME::FileSystem::FileInfo& _fileInfo)const noexcept
	{
		return _fileInfo.getHash();
	}
};

#endif // CANDY_FILE_SYSTEM_FILE_INFO_H
