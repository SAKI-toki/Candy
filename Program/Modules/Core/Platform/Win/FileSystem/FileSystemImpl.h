/*****************************************************************//**
 * \file   FileSystemImpl.h
 * \brief  ファイルシステムの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_IMPL_H
#define CANDY_CORE_FILE_SYSTEM_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem::Impl
{
	// ファイル読み込み
	bool FileRead(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_IMPL_H
