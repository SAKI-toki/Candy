/*****************************************************************//**
 * \file   FileSystemImpl.cpp
 * \brief  ファイルシステムの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

// ファイル読み込み
void FileSystem::Impl::FileRead(const HANDLE _handle, std::byte* _buf, const u64 _readSize)
{
	::SetFilePointer(_handle, 0, nullptr, FILE_BEGIN);
	if (!::ReadFile(_handle, static_cast<void*>(_buf), static_cast<DWORD>(sizeof(std::byte) * _readSize), nullptr, nullptr))
	{
		CANDY_LOG_ERR("ファイルの読み込みに失敗");
	}
}

CANDY_CORE_NAMESPACE_END
