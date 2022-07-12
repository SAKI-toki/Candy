/*****************************************************************//**
 * \file   FileSystemFileEnumeratorImpl.h
 * \brief  ファイルシステムのファイル列挙の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_IMPL_H
#define CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileEnumeratorImpl
	{
	protected:
		void startup(const std::string& _basePath);
		
		bool next();
		bool isDirectory()const;

		std::string getPath()const;

	private:
		HANDLE m_CurrentFileHandle;
		WIN32_FIND_DATA m_FindData;
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_IMPL_H
