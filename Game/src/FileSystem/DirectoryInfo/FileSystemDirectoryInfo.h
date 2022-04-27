#ifndef CANDY_FILE_SYSTEM_DIRECTORY_INFO_H
#define CANDY_FILE_SYSTEM_DIRECTORY_INFO_H

#include <FileSystem/FileInfo/FileSystemFileInfo.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class DirectoryInfo
	{
	public:
		void setName(const std::string& _name);
		void setHash(const u32 _hash);
		void addDirectoryInfo(const DirectoryInfo& _directoryInfo);
		void addFileInfo(const FileInfo& _fileInfo);

	private:
		std::string m_Name;
		u32 m_Hash;
		std::vector<DirectoryInfo> m_DirectoryInfos;
		std::vector<FileInfo> m_FileInfos;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_DIRECTORY_INFO_H
