#ifndef CANDY_FILE_SYSTEM_FILE_INFO_H
#define CANDY_FILE_SYSTEM_FILE_INFO_H

#include <FileSystem/FileHandle/FileSystemFileHandle.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileInfo
	{
	public:
		void setName(const std::string& _name);
		void setHash(const u32 _hash);
		void setFileHandle(const FileHandle _fileHandle);

	private:
		std::string m_Name;
		u32 m_Hash;
		FileHandle m_FileHandle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_INFO_H
