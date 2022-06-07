/*****************************************************************//**
 * \file   FileSystemWorkHandle.cpp
 * \brief  ファイルシステムのワークハンドル
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemWorkHandle.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// 終了判定
	bool WorkHandle::isEnd()const
	{
		return FileSystem::IsEndReadWork(*this);
	}
}

CANDY_NAMESPACE_END
