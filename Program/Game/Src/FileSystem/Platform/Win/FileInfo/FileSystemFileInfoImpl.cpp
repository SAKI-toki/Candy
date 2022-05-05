#include "FileSystemFileInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	bool FileInfoImpl::mount(const std::string& _path)
	{
		m_FileHandle = ::CreateFile(_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
			nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		return m_FileHandle != INVALID_HANDLE_VALUE;
	}

	void FileInfoImpl::close()
	{
		::CloseHandle(m_FileHandle);
	}

	u64 FileInfoImpl::getSize()const
	{
		return static_cast<u64>(::GetFileSize(m_FileHandle, nullptr));
	}

	HANDLE FileInfoImpl::getHandle()const
	{
		return m_FileHandle;
	}
}

CANDY_NAMESPACE_END
