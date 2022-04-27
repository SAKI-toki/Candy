#include "FileSystemFileInfo.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void FileInfo::setName(const std::string& _name)
	{
		m_Name = _name;
	}

	void FileInfo::setHash(const u32 _hash)
	{
		m_Hash = _hash;
	}

	void FileInfo::setFileHandle(const FileHandle _fileHandle)
	{
		m_FileHandle = _fileHandle;
	}
}

CANDY_NAMESPACE_END
