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

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work
	{
	public:
		// 初期化
		void startup(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo);
		// 破棄
		void cleanup();

		// パスの取得
		std::string getPath()const;
		// ハッシュの取得
		u32 getHash()const;
		// バッファ情報の取得
		const std::shared_ptr<BufferInfo>& getBufferInfo();

	private:
		std::string m_Path{};
		u32 m_Hash{};
		std::shared_ptr<BufferInfo> m_BufferInfo{};
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_WORK_H
