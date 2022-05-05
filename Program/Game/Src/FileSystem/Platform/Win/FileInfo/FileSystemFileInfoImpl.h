#ifndef CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
#define CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileInfoImpl
	{
	protected:
		bool mount(const std::string& _path);
		void close();

		u64 getSize()const;

	public:
		HANDLE getHandle()const;

	private:
		HANDLE m_FileHandle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
