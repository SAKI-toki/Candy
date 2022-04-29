#include "FileSystemWorkHandle.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	bool WorkHandle::isEnd()const
	{
		return IsEndReadWork(*this);
	}
}

CANDY_NAMESPACE_END
