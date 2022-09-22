/*****************************************************************//**
 * \file   FileSystem.h
 * \brief  ファイルシステム
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_H
#define CANDY_CORE_FILE_SYSTEM_H

#include <Core/CoreInclude.h>

#include "FileSystemDef.h"

#include "Work/FileSystemWork.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void Startup();
	// 更新
	void Cleanup();

	// 読み込みリクエスト
	std::weak_ptr<Work> RequestRead(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo);
	// 読み込みリクエスト(即時)
	bool RequestReadNoWait(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo);
	// ファイル読み込み終了判定
	bool IsEndReadWork(const std::weak_ptr<Work>& _work);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_H
