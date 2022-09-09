/*****************************************************************//**
 * \file   FileSystemDef.h
 * \brief  ファイルシステムの定義
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_FILE_SYSTEM_DEF_H
#define CANDY_CORE_FILE_SYSTEM_DEF_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	struct BufferInfo
	{
		std::shared_ptr<std::byte[]> m_Buffer;
		u64 m_BufferSize{};
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_SYSTEM_DEF_H
