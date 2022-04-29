#ifndef CANDY_FILE_SYSTEM_WORK_HANDLE_H
#define CANDY_FILE_SYSTEM_WORK_HANDLE_H

#include <Handle/Handle.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work;
	class WorkHandle : public Handle<Work, WorkHandle>
	{
	public:
		bool isEnd()const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_WORK_HANDLE_H
