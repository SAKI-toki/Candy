#include "FileSystemFileEnumerator.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void FileEnumerator::startup(const std::string& _basePath)
	{
		FileEnumeratorImpl::startup(_basePath);
	}

	bool FileEnumerator::next()
	{
		return FileEnumeratorImpl::next();
	}

	bool FileEnumerator::isDirectory()const
	{
		return FileEnumeratorImpl::isDirectory();
	}

	std::string FileEnumerator::getPath()const
	{
		return FileEnumeratorImpl::getPath();
	}
}

CANDY_NAMESPACE_END
