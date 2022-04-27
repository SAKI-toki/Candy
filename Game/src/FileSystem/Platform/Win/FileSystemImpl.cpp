#include "FileSystemImpl.h"
#include "FileHandle/FileSystemFileHandleImpl.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem::Impl
{
	DirectoryInfo GetFileInfosRecursive(const std::string& _path, const std::string& _directoryName, const bool _isRoot);
}

void FileSystem::Impl::Startup()
{
	Setting::GetDataPath();
}

void FileSystem::Impl::Cleanup()
{

}

FileSystem::DirectoryInfo FileSystem::Impl::GetFileInfos(const std::string& _basePath)
{
	return GetFileInfosRecursive(_basePath, "Root", true);
}

FileSystem::DirectoryInfo FileSystem::Impl::GetFileInfosRecursive(const std::string& _path, const std::string& _directoryName, const bool _isRoot)
{
	DirectoryInfo directoryInfo;
	directoryInfo.setName(_directoryName);
	directoryInfo.setHash(Fnv::Hash32Low(_directoryName.c_str()));

	WIN32_FIND_DATA findData;
	HANDLE handle;

	if (_isRoot)
	{
		handle = ::FindFirstFile((_path + R"(\*)").c_str(), &findData);
	}
	else
	{
		handle = ::FindFirstFile((_path + R"(\)" + _directoryName + R"(\*)").c_str(), &findData);
	}

	// 空のディレクトリ
	if (handle == INVALID_HANDLE_VALUE)
	{
		return directoryInfo;
	}

	do
	{
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (findData.cFileName != std::string{ "." } &&
				findData.cFileName != std::string{ ".." })
			{
				directoryInfo.addDirectoryInfo(GetFileInfosRecursive(_path, findData.cFileName, false));
			}
		}
		else
		{
			FileInfo fileInfo;
			fileInfo.setName(findData.cFileName);
			fileInfo.setHash(Fnv::Hash32Low(findData.cFileName));
			fileInfo.setFileHandle(FileHandle{ FileHandleImpl{ handle } });
			directoryInfo.addFileInfo(fileInfo);
		}
	} while (FindNextFile(handle, &findData) != 0);

	return directoryInfo;
}

CANDY_NAMESPACE_END
