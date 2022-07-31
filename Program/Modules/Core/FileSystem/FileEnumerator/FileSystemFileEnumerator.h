/*****************************************************************//**
 * \file   FileSystemFileEnumerator.h
 * \brief  ファイルシステムのファイル列挙
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_H
#define CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/FileSystem/FileEnumerator/FileSystemFileEnumeratorImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	// ファイル列挙
	class FileEnumerator : public FileEnumeratorImpl
	{
	public:
		// 初期化
		void startup(const std::string_view _basePath);

		// 次のファイルへ
		bool next();
		// ディレクトリーか
		bool isDirectory()const;

		// パス取得
		std::string getPath()const;
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_FILE_ENUMERATOR_H
