#ifndef CANDY_FILE_SYSTEM_IMPL_H
#define CANDY_FILE_SYSTEM_IMPL_H

#include <FileSystem/DirectoryInfo/FileSystemDirectoryInfo.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem::Impl
{
	void Startup();
	void Cleanup();

	DirectoryInfo GetFileInfos(const std::string& _basePath);
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_IMPL_H
