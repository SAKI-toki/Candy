#include "FileSystemWork.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	void Work::startup(const u32 _hash, std::byte* _buf)
	{
		m_Hash = _hash;
		m_Buffer = _buf;
	}

	void Work::cleanup()
	{

	}

	WorkHandle Work::getHandle()const
	{
		return m_Handle;
	}

	u32 Work::getHash()const
	{
		return m_Hash;
	}

	std::byte* Work::getBuffer()const
	{
		return m_Buffer;
	}

	void Work::setHandle(const WorkHandle _handle)
	{
		m_Handle = _handle;
	}
}

CANDY_NAMESPACE_END
