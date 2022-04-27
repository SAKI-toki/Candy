#include "FileSystem.h"
#include "DirectoryInfo/FileSystemDirectoryInfo.h"

#if PLATFORM_WIN
#include "Platform/Win/FileSystemImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	DirectoryInfo m_RootDirectoryInfo;
}

void FileSystem::Startup()
{
	Impl::Startup();

	m_RootDirectoryInfo = Impl::GetFileInfos(Setting::GetDataPath());
}

void FileSystem::Cleanup()
{
	Impl::Cleanup();
}

CANDY_NAMESPACE_END
