#ifndef CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
#define CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H

#if PLATFORM_WIN
#include <FileSystem/Platform/Win/FileEnumerator/FileSystemFileEnumeratorImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileEnumerator : public FileEnumeratorImpl
	{
	public:
		void startup(const std::string& _basePath);

		bool next();
		bool isDirectory()const;

		std::string getPath()const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
