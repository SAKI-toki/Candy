#include "FileSystemFileHandleImpl.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	FileHandleImpl::FileHandleImpl()
	{

	}

	FileHandleImpl::FileHandleImpl(const HANDLE _handle) :
		m_Handle{ _handle }
	{

	}

	void FileHandleImpl::setHandle(const HANDLE _handle)
	{
		m_Handle = _handle;
	}
}

CANDY_NAMESPACE_END
