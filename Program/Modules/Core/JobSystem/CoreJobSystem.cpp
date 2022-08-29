/*****************************************************************//**
 * \file   CoreJobSystem.cpp
 * \brief  ジョブシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "CoreJobSystem.h"

CANDY_CORE_NAMESPACE_BEGIN

// 初期化
void JobSystem::startup(const s32 _threadCount, const s32 _minCoreNo, const s32 _maxCoreNo)
{
	m_ThreadInfos.resize(_threadCount);
	for (s32 i = 0; i < _threadCount; ++i)
	{
		CreateThreadOption createThreadOption;
		createThreadOption.m_CoreNo = LoopStrictInt(i + _minCoreNo, _minCoreNo, _maxCoreNo);
		createThreadOption.m_Priority = THREAD_PRIORITY::HIGHEST;
		m_ThreadInfos[i].m_ExecThreadEvent.startup();
		m_ThreadInfos[i].m_EndThreadEvent.startup();
		m_ThreadInfos[i].m_Thread.create(ThreadFunc, (void*)&m_ThreadInfos[i], createThreadOption);
	}
}

// 破棄
void JobSystem::cleanup()
{
	reset();
	for (auto& threadInfo : m_ThreadInfos)
	{
		threadInfo.m_Thread.close();
		threadInfo.m_ExecThreadEvent.cleanup();
		threadInfo.m_EndThreadEvent.cleanup();
	}
	m_ThreadInfos.clear();
}

// 関数セット
void JobSystem::setFunction(std::function<void()>&& _func, const s32 _execThreadCount)
{
	if (m_ExecuteCount + _execThreadCount > getThreadCount())
	{
		CANDY_LOG_WARN("スレッド実行数が多すぎます");
	}
	for (s32 i = 0; i < _execThreadCount; ++i)
	{
		m_ThreadInfos[m_ExecuteCount + i].m_Function = _func;
	}
	m_ExecuteCount = Clamp(m_ExecuteCount + _execThreadCount, 1, getThreadCount());
}

// 関数セット
void JobSystem::setFunctions(const std::vector<std::function<void()>>& _funcs)
{
	CANDY_ASSERT(m_ExecuteCount + _funcs.size() <= getThreadCount());

	for (s32 i = 0; i < (s32)_funcs.size(); ++i)
	{
		m_ThreadInfos[m_ExecuteCount + i].m_Function = _funcs[i];
	}

	m_ExecuteCount += (s32)_funcs.size();
}

// 実行
void JobSystem::execute()
{
	for (s32 i = 0; i < m_ExecuteCount; ++i)
	{
		m_ThreadInfos[i].m_ExecThreadEvent.signal();
	}
}

// 待機
void JobSystem::wait()
{
	for (s32 i = 0; i < m_ExecuteCount; ++i)
	{
		m_ThreadInfos[i].m_EndThreadEvent.wait();
	}
}

// リセット
void JobSystem::reset()
{
	m_ExecuteCount = 0;
}

// スレッド数の取得
s32 JobSystem::getThreadCount()const
{
	return (s32)m_ThreadInfos.size();
}

// スレッド実行関数
void JobSystem::ThreadFunc(void* _threadInfo)
{
	ThreadInfo& threadInfo = *(ThreadInfo*)(_threadInfo);

	while (true)
	{
		threadInfo.m_ExecThreadEvent.wait();
		if (threadInfo.m_Function)threadInfo.m_Function();
		threadInfo.m_EndThreadEvent.signal();
	}
}

CANDY_CORE_NAMESPACE_END
