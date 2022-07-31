/*****************************************************************//**
 * \file   FileSystemFileEnumeratorImpl.cpp
 * \brief  ファイルシステムのファイル列挙の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileEnumeratorImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	void FileEnumeratorImpl::startup(const std::string_view _basePath)
	{
		auto path = std::format(R"({0}\*)", _basePath);
		m_CurrentFileHandle = ::FindFirstFile(path.c_str(), &m_FindData);
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

CANDY_CORE_NAMESPACE_END
