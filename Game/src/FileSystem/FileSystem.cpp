#include "FileSystem.h"
#include "FileInfo/FileSystemFileInfo.h"
#include "FileEnumerator/FileSystemFileEnumerator.h"
#include <Thread/ThreadSystem.h>
#include <Handle/HandleSystem.h>
#include <Flow/Main/MainFlow.h>

#if PLATFORM_WIN
#include "Platform/Win/FileSystemImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	std::unordered_set<FileInfo> m_FileInfos;
	HandleSystem<Work, WorkHandle> m_WorkHandleSystem;
	std::queue<Work*> m_Works;
	Thread m_FileReadThread;

	void FileReadThreadunc();
	void FileRead(Work* const _work);
	void CreateFileInfo(const std::string& _basePath);
}

void FileSystem::Startup()
{
	CreateFileInfo(Setting::GetDataPath());
	CreateThreadOption threadOption;
	threadOption.m_Priority = THREAD_PRIORITY::LOWEST;
	threadOption.m_CoreNo = 1;
	m_FileReadThread.create([](void*) { FileReadThreadunc(); }, nullptr, threadOption);
	m_WorkHandleSystem.startup();
}

void FileSystem::Cleanup()
{
	for (auto fileInfo : m_FileInfos)fileInfo.cleanup();
	m_FileInfos.clear();
}

u64 FileSystem::GetFileSize(const std::string& _path)
{
	const u32 hash = Fnv::Hash32Low(Path::FormatPath(_path));
	auto itr = std::find(m_FileInfos.begin(), m_FileInfos.end(), hash);
	if (itr == m_FileInfos.end())
	{
		CANDY_LOG("ファイルが見つかりませんでした");
		return 0;
	}
	return itr->getSize();
}

FileSystem::WorkHandle FileSystem::RequestRead(const std::string& _path, std::byte* const _buf, u64 _bufSize)
{
	const u32 hash = Fnv::Hash32Low(Path::FormatPath(_path));
	auto itr = std::find(m_FileInfos.begin(), m_FileInfos.end(), hash);
	if (itr == m_FileInfos.end())
	{
		CANDY_LOG("ファイルが見つかりませんでした");
		return WorkHandle{};
	}
	if (itr->getSize() > _bufSize)
	{
		CANDY_LOG("バッファのサイズが足りません");
		return WorkHandle{};
	}

	Work* work = new Work();
	work->startup(hash, _buf);
	work->setHandle(m_WorkHandleSystem.createHandle(work));
	m_Works.push(work);
	return work->getHandle();
}

bool FileSystem::IsEndReadWork(const WorkHandle _handle)
{
	return !m_WorkHandleSystem.getPtr(_handle);
}

void FileSystem::FileReadThreadunc()
{
	while (true)
	{
		if (MainFlow::IsEnd())break;

		if (m_Works.empty())
		{
			ThreadSystem::SleepThread(1);
			continue;
		}

		auto work = m_Works.front();
		
		FileRead(work);

		m_WorkHandleSystem.releaseHandle(work->getHandle());
		delete work;
		m_Works.pop();
	}
	while (!m_Works.empty()) { m_WorkHandleSystem.releaseHandle(m_Works.front()->getHandle()); delete m_Works.front(); m_Works.pop(); }
}

void FileSystem::FileRead(Work* const _work)
{
	auto itr = std::find(m_FileInfos.begin(), m_FileInfos.end(), _work->getHash());
	if (itr == m_FileInfos.end())
	{
		CANDY_LOG("読み込み失敗");
		return;
	}

	Impl::FileRead(itr->getHandle(), _work->getBuffer(), itr->getSize());
}

void FileSystem::CreateFileInfo(const std::string& _basePath)
{
	m_FileInfos.clear();

	FileEnumerator fileEnumrator;
	fileEnumrator.startup(_basePath);

	while (fileEnumrator.next())
	{
		const auto path = _basePath + R"(\)" + fileEnumrator.getPath();
		if (fileEnumrator.isDirectory())
		{
			if (*path.rbegin() != '.')
			{
				CreateFileInfo(path);
			}
		}
		else
		{
			FileInfo fileInfo;
			fileInfo.startup(path);
			m_FileInfos.insert(fileInfo);
		}
	}
}

CANDY_NAMESPACE_END
