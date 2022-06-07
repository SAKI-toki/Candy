/*****************************************************************//**
 * \file   FileSystemFileInfoImpl.h
 * \brief  ファイルシステムのファイル情報(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
#define CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class FileInfoImpl
	{
	protected:
		// マウント
		bool mount(const std::string& _path);

		// ファイルを閉じる
		void close();
		
		// ファイルサイズの取得
		u64 getSize()const;

	public:
		// ファイルハンドルの取得
		HANDLE getHandle()const;

	private:
		HANDLE m_FileHandle;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_INFO_IMPL_H
