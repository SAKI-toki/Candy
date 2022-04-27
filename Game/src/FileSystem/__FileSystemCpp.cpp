#include "FileSystem.cpp"
#include "FileInfo/FileSystemFileInfo.cpp"
#include "FileHandle/FileSystemFileHandle.cpp"
#include "DirectoryInfo/FileSystemDirectoryInfo.cpp"

#if PLATFORM_WIN
#include "Platform/Win/FileSystemImpl.cpp"
#include "Platform/Win/FileHandle/FileSystemFileHandleImpl.cpp"
#endif // PLATFORM_WIN
