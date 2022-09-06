/*****************************************************************//**
 * \file   FileSystemWork.h
 * \brief  ファイルシステムのワーク
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_WORK_H
#define CANDY_CORE_FILE_SYSTEM_WORK_H

#include <Core/CoreInclude.h>

#include <Core/FileSystem/FileSystemDef.h>
#include "FileSystemWorkHandle.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work
	{
	public:
		// 初期化
		void startup(const std::string_view _path, BufferInfo* const _bufferInfo);
		// 破棄
		void cleanup();

		// ワークハンドルの取得
		WorkHandle getHandle()const;
		// パスの取得
		std::string getPath()const;
		// ハッシュの取得
		u32 getHash()const;
		// バッファ情報の取得
		BufferInfo* getBufferInfo();

		// ハンドルのセット
		void setHandle(const WorkHandle _handle);

	private:
		WorkHandle m_Handle{};
		std::string m_Path{};
		u32 m_Hash{};
		BufferInfo* m_BufferInfo{};
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_WORK_H
