/*****************************************************************//**
 * \file   CoreJobSystem.h
 * \brief  ジョブシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CORE_JOB_SYSTEM_H
#define CORE_JOB_SYSTEM_H

#include <Core/CoreInclude.h>
#include <Core/Thread/Thread.h>
#include <Core/Thread/ThreadSystem.h>
#include <Core/Mutex/ThreadEvent.h>

CANDY_CORE_NAMESPACE_BEGIN

class JobSystem
{
public:
	void startup(const s32 _threadCount, const s32 _minCoreNo, const s32 _maxCoreNo, const THREAD_PRIORITY _priority = THREAD_PRIORITY::NORMAL);
	void startup(const s32* const _coreNoList, const s32 _count, const THREAD_PRIORITY _priority = THREAD_PRIORITY::NORMAL);
	void cleanup();

	void setFunction(std::function<void()>&& _func, const s32 _execThreadCount = 1);
	void setFunctions(const std::vector<std::function<void()>>& _funcs);
	void execute();
	void wait();
	void reset();

	s32 getThreadCount()const;

private:
	struct ThreadInfo
	{
		Thread m_Thread;
		std::function<void()> m_Function;
		ThreadEvent m_ExecThreadEvent;
		ThreadEvent m_EndThreadEvent;
	};
	std::vector<ThreadInfo> m_ThreadInfos;
	s32 m_ExecuteCount{};

	static void ThreadFunc(void* _threadInfo);
};

CANDY_CORE_NAMESPACE_END

#endif // CORE_JOB_SYSTEM_H
