#ifndef CANDY_FILE_SYSTEM_FILE_HANDLE_H
#define CANDY_FILE_SYSTEM_FILE_HANDLE_H

#if PLATFORM_WIN
#include <FileSystem/Platform/Win/FileHandle/FileSystemFileHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileHandle : public FileHandleImpl
	{

	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_HANDLE_H
