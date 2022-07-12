/*****************************************************************//**
 * \file   FileSystemFileInfo.h
 * \brief  ファイルシステムのファイル情報
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_FILE_INFO_H
#define CANDY_CORE_FILE_SYSTEM_FILE_INFO_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/FileSystem/FileInfo/FileSystemFIleInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

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

CANDY_CORE_NAMESPACE_END

template<>
struct std::hash<candy::core::FileSystem::FileInfo>
{
	size_t operator()(const candy::core::FileSystem::FileInfo& _fileInfo)const noexcept
	{
		return _fileInfo.getHash();
	}
};

#endif // CANDY_CORE_FILE_SYSTEM_FILE_INFO_H
