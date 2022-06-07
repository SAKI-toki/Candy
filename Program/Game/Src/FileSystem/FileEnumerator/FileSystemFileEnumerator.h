/*****************************************************************//**
 * \file   FileSystemFileEnumerator.h
 * \brief  ファイルシステムのファイル列挙
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
#define CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H

#if PLATFORM_WIN
#include <FileSystem/Platform/Win/FileEnumerator/FileSystemFileEnumeratorImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// ファイル列挙
	class FileEnumerator : public FileEnumeratorImpl
	{
	public:
		// 初期化
		void startup(const std::string& _basePath);

		// 次のファイルへ
		bool next();
		// ディレクトリーか
		bool isDirectory()const;

		// パス取得
		std::string getPath()const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_FILE_ENUMERATOR_H
