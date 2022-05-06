#ifndef CANDY_FILE_SYSTEM_WORK_H
#define CANDY_FILE_SYSTEM_WORK_H

#include "FileSystemWorkHandle.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work
	{
	public:
		void startup(const u32 _hash, std::byte* const _buf);
		void cleanup();

		WorkHandle getHandle()const;
		u32 getHash()const;
		std::byte* getBuffer()const;

		void setHandle(const WorkHandle _handle);

	private:
		WorkHandle m_Handle{};
		u32 m_Hash{};
		std::byte* m_Buffer = nullptr;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_WORK_H
