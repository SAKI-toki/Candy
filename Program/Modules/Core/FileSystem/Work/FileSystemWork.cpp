/*****************************************************************//**
 * \file   FileSystemWork.cpp
 * \brief  ファイルシステムのワーク
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemWork.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void Work::startup(const std::string_view _path, BufferInfo* const _bufferInfo)
	{
		m_Path = _path;
		m_Hash = Fnv::Hash32Low(_path);
		m_BufferInfo = _bufferInfo;
	}

	// 破棄
	void Work::cleanup()
	{

	}

	// ワークハンドルの取得
	WorkHandle Work::getHandle()const
	{
		return m_Handle;
	}

	// パスの取得
	std::string Work::getPath()const
	{
		return m_Path;
	}

	// ハッシュの取得
	u32 Work::getHash()const
	{
		return m_Hash;
	}

	// バッファ情報の取得
	BufferInfo* Work::getBufferInfo()
	{
		return m_BufferInfo;
	}

	// ハンドルのセット
	void Work::setHandle(const WorkHandle _handle)
	{
		m_Handle = _handle;
	}
}

CANDY_CORE_NAMESPACE_END
