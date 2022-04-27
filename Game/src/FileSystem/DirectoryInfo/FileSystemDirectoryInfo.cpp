#include "FileSystemDirectoryInfo.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void DirectoryInfo::setName(const std::string& _name)
	{
		m_Name = _name;
	}

	void DirectoryInfo::setHash(const u32 _hash)
	{
		m_Hash = _hash;
	}

	void DirectoryInfo::addDirectoryInfo(const DirectoryInfo& _directoryInfo)
	{
		m_DirectoryInfos.push_back(_directoryInfo);
	}

	void DirectoryInfo::addFileInfo(const FileInfo& _fileInfo)
	{
		m_FileInfos.push_back(_fileInfo);
	}
}

CANDY_NAMESPACE_END
