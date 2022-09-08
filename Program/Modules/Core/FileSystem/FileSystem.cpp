/*****************************************************************//**
 * \file   FileSystem.cpp
 * \brief  ファイルシステム
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystem.h"
#include "FileEnumerator/FileSystemFileEnumerator.h"
#include <Core/Thread/ThreadSystem.h>
#include <Core/Handle/HandleSystem.h>
#include <Core/Mutex/CriticalSection.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/FileSystem/FileSystemImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

namespace FileSystem
{
	std::unordered_set<u32> m_FilePathHashes;
	HandleSystem<Work, WorkHandle> m_WorkHandleSystem;
	std::queue<Work*> m_Works;
	Thread m_FileReadThread;
	CriticalSection m_Cs;
	bool m_EndFileReadThread;

	// ファイル読み込みのスレッド実行関数
	void FileReadThreadFunc();
	// ファイル読み込み
	bool FileRead(Work* const _work);
	// ファイルパスのハッシュリストの作成
	void CreateFilePathHashList(std::string_view _basePath);
	// 読み込みリクエストのワーク作成
	Work* CreateRequestReadWork(std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo);
}

// 初期化
void FileSystem::Startup()
{
	m_Cs.startup();
	m_EndFileReadThread = false;
	CreateFilePathHashList(Config::GetDataPath());
	CreateThreadOption threadOption;
	threadOption.m_Priority = THREAD_PRIORITY::LOWEST;
	threadOption.m_CoreNo = 1;
	m_FileReadThread.create([](void*) { FileReadThreadFunc(); }, nullptr, threadOption);
	m_WorkHandleSystem.startup();
}

// 更新
void FileSystem::Cleanup()
{
	m_EndFileReadThread = true;
	m_FileReadThread.wait();
	while (!m_Works.empty()) { delete m_Works.front(); m_Works.pop(); }
	m_WorkHandleSystem.cleanup();
	m_FilePathHashes.clear();
	m_Cs.cleanup();
}

// 読み込みリクエスト
FileSystem::WorkHandle FileSystem::RequestRead(std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo)
{
	Work* work = CreateRequestReadWork(_path, _bufferInfo);
	if (!work)return WorkHandle{};

	work->setHandle(m_WorkHandleSystem.createHandle(work));
	{
		CANDY_CRITICAL_SECTION_SCOPE(m_Cs);
		m_Works.push(work);
	}

	return work->getHandle();
}

// 読み込みリクエスト(即時)
bool FileSystem::RequestReadNoWait(std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo)
{
	Work* work = CreateRequestReadWork(_path, _bufferInfo);
	if (!work)return false;

	CANDY_CRITICAL_SECTION_SCOPE(m_Cs);
	return FileRead(work);
}

// ファイル読み込み終了判定
bool FileSystem::IsEndReadWork(const WorkHandle& _handle)
{
	return !m_WorkHandleSystem.getPtr(_handle);
}

// ファイル読み込みのスレッド実行関数
void FileSystem::FileReadThreadFunc()
{
	while (true)
	{
		// 終了
		if (m_EndFileReadThread)break;

		// 空ならスレッドスリープ
		if (m_Works.empty())
		{
			ThreadSystem::SleepThread(1);
			continue;
		}

		CANDY_CRITICAL_SECTION_SCOPE(m_Cs);
		auto work = m_Works.front();
		
		FileRead(work);

		m_WorkHandleSystem.releaseHandle(work->getHandle());
		delete work;
		m_Works.pop();
	}
}

// ファイル読み込み
bool FileSystem::FileRead(Work* const _work)
{
	auto itr = m_FilePathHashes.find(_work->getHash());
	if (itr == m_FilePathHashes.end())
	{
		CANDY_LOG("ファイルが見つかりません");
		return false;
	}

	Impl::FileRead(_work->getPath(), _work->getBufferInfo());

	return true;
}

// ファイル情報リストの作成
void FileSystem::CreateFilePathHashList(const std::string_view _basePath)
{
	FileEnumerator fileEnumrator;
	fileEnumrator.startup(_basePath);

	while (fileEnumrator.next())
	{
		const auto path = std::format(R"({0}\{1})", _basePath, fileEnumrator.getPath());
		if (fileEnumrator.isDirectory())
		{
			// カレントディレクトリは無視
			if (*path.rbegin() != '.')
			{
				CreateFilePathHashList(path);
			}
		}
		else
		{
			const u32 hash = Fnv::Hash32Low(Path::FormatPath(path));
			CANDY_ASSERT(!m_FilePathHashes.contains(hash));
			m_FilePathHashes.insert(hash);
		}
	}
}

// 読み込みリクエストのワーク作成
FileSystem::Work* FileSystem::CreateRequestReadWork(const std::string_view _path, const std::shared_ptr<BufferInfo>& _bufferInfo)
{
	const auto path = Path::FormatPath(_path);
	const u32 hash = Fnv::Hash32Low(path);
	auto itr = m_FilePathHashes.find(hash);
	if (itr == m_FilePathHashes.end())
	{
		CANDY_LOG("ファイルが見つかりませんでした");
		return nullptr;
	}

	Work* work = new Work();
	work->startup(path, _bufferInfo);
	return work;
}

CANDY_CORE_NAMESPACE_END
