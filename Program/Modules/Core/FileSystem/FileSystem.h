/*****************************************************************//**
 * \file   FileSystem.h
 * \brief  ファイルシステム
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_H
#define CANDY_CORE_FILE_SYSTEM_H

#include <Core/CoreInclude.h>

#include "Work/FileSystemWork.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void Startup();
	// 更新
	void Cleanup();

	// ファイルサイズの取得
	u64 GetFileSize(const std::string_view _path);
	// 読み込みリクエスト
	WorkHandle RequestRead(const std::string_view _path, std::byte* const _buf, u64 _bufSize);
	// 読み込みリクエスト(即時)
	bool RequestReadNoWait(const std::string_view _path, std::byte* const _buf, u64 _bufSize);
	// ファイル読み込み終了判定
	bool IsEndReadWork(const WorkHandle _handle);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_H
