#ifndef CANDY_FILE_SYSTEM_FILE_HANDLE_IMPL_H
#define CANDY_FILE_SYSTEM_FILE_HANDLE_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileHandleImpl
	{
	public:
		FileHandleImpl();
		explicit FileHandleImpl(const HANDLE _handle);

		void setHandle(const HANDLE _handle);

	private:
		HANDLE m_Handle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_HANDLE_IMPL_H
