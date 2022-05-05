#include "FileSystemImpl.h"

CANDY_NAMESPACE_BEGIN

void FileSystem::Impl::FileRead(const HANDLE _handle, std::byte* _buf, const u64 _readSize)
{
	::SetFilePointer(_handle, 0, nullptr, FILE_BEGIN);
	::ReadFile(_handle, static_cast<void*>(_buf), static_cast<DWORD>(sizeof(std::byte) * _readSize), nullptr, nullptr);
}

CANDY_NAMESPACE_END
