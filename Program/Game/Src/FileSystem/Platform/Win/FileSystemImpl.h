/*****************************************************************//**
 * \file   FileSystemImpl.h
 * \brief  ファイルシステムの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_IMPL_H
#define CANDY_FILE_SYSTEM_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace FileSystem::Impl
{
	// ファイル読み込み
	void FileRead(const HANDLE _handle, std::byte* _buf, const u64 _readSize);
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_IMPL_H
