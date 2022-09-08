/*****************************************************************//**
 * \file   FileSystemImpl.cpp
 * \brief  ファイルシステムの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

// ファイル読み込み
bool FileSystem::Impl::FileRead(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo)
{
	HANDLE fileHandle = ::CreateFile(_path.data(), GENERIC_READ, FILE_SHARE_READ,
		nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (fileHandle == INVALID_HANDLE_VALUE)return false;

	const u64 fileSize = static_cast<u64>(::GetFileSize(fileHandle, nullptr));
	_bufferInfo->m_Buffer = std::make_unique<std::byte[]>(fileSize);
	_bufferInfo->m_BufferSize = fileSize;

	::SetFilePointer(fileHandle, 0, nullptr, FILE_BEGIN);
	if (!::ReadFile(fileHandle, static_cast<void*>(_bufferInfo->m_Buffer.get()), static_cast<DWORD>(sizeof(std::byte) * fileSize), nullptr, nullptr))
	{
		CANDY_LOG_ERR("ファイルの読み込みに失敗");
	}

	::CloseHandle(fileHandle);

	return true;
}

CANDY_CORE_NAMESPACE_END
