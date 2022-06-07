/*****************************************************************//**
 * \file   FileSystemFileEnumeratorImpl.cpp
 * \brief  ファイルシステムのファイル列挙の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileEnumeratorImpl.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void FileEnumeratorImpl::startup(const std::string& _basePath)
	{
		m_CurrentFileHandle = ::FindFirstFile((_basePath + R"(\*)").c_str(), &m_FindData);
	}

	bool FileEnumeratorImpl::next()
	{
		return ::FindNextFile(m_CurrentFileHandle, &m_FindData);
	}

	bool FileEnumeratorImpl::isDirectory()const
	{
		return m_FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
	}

	std::string FileEnumeratorImpl::getPath()const
	{
		return m_FindData.cFileName;
	}
}

CANDY_NAMESPACE_END
