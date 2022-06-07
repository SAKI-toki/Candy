/*****************************************************************//**
 * \file   FileSystemWork.cpp
 * \brief  ファイルシステムのワーク
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemWork.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// 初期化
	void Work::startup(const u32 _hash, std::byte* _buf)
	{
		m_Hash = _hash;
		m_Buffer = _buf;
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

	// ハッシュの取得
	u32 Work::getHash()const
	{
		return m_Hash;
	}

	// バッファの取得
	std::byte* Work::getBuffer()const
	{
		return m_Buffer;
	}

	// ハンドルのセット
	void Work::setHandle(const WorkHandle _handle)
	{
		m_Handle = _handle;
	}
}

CANDY_NAMESPACE_END
