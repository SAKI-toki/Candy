#ifndef CANDY_FILE_SYSTEM_H
#define CANDY_FILE_SYSTEM_H

#include "Work/FileSystemWork.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void Startup();
	void Cleanup();

	u64 GetFileSize(const std::string& _path);
	WorkHandle RequestRead(const std::string& _path, std::byte* const _buf, u64 _bufSize);
	bool IsEndReadWork(const WorkHandle _handle);
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_H
