/*****************************************************************//**
 * \file   JobSystem.h
 * \brief  ジョブシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_JOB_SYSTEM_H
#define CANDY_JOB_SYSTEM_H

#include <Thread/ThreadSystem.h>
#include <Mutex/ThreadEvent.h>

CANDY_NAMESPACE_BEGIN

class JobSystem
{
public:
	void startup(const s32 _threadCount, const s32 _minCoreNo, const s32 _maxCoreNo);
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
	s32 m_ExecuteCount;

	static void ThreadFunc(void* _threadInfo);
};

CANDY_NAMESPACE_END

#endif // CANDY_JOB_SYSTEM_H
