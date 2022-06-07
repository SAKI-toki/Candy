/*****************************************************************//**
 * \file   FileSystemFileEnumerator.cpp
 * \brief  ファイルシステムのファイル列挙
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemFileEnumerator.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void FileEnumerator::startup(const std::string& _basePath)
	{
		FileEnumeratorImpl::startup(_basePath);
	}

	// 次のファイルへ
	bool FileEnumerator::next()
	{
		return FileEnumeratorImpl::next();
	}

	// ディレクトリーか
	bool FileEnumerator::isDirectory()const
	{
		return FileEnumeratorImpl::isDirectory();
	}

	// パス取得
	std::string FileEnumerator::getPath()const
	{
		return FileEnumeratorImpl::getPath();
	}
}

CANDY_NAMESPACE_END
