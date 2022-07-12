/*****************************************************************//**
 * \file   FileSystemWork.h
 * \brief  ファイルシステムのワーク
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_WORK_H
#define CANDY_CORE_FILE_SYSTEM_WORK_H

#include <Core/CoreInclude.h>

#include "FileSystemWorkHandle.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work
	{
	public:
		// 初期化
		void startup(const u32 _hash, std::byte* const _buf);
		// 破棄
		void cleanup();

		// ワークハンドルの取得
		WorkHandle getHandle()const;
		// ハッシュの取得
		u32 getHash()const;
		// バッファの取得
		std::byte* getBuffer()const;

		// ハンドルのセット
		void setHandle(const WorkHandle _handle);

	private:
		WorkHandle m_Handle{};
		u32 m_Hash{};
		std::byte* m_Buffer = nullptr;
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_WORK_H
