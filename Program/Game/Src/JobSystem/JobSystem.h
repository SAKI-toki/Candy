/*****************************************************************//**
 * \file   JobSystem.h
 * \brief  ジョブシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef JOB_SYSTEM_H
#define JOB_SYSTEM_H

#include <GameInclude.h>

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
		core::Thread m_Thread;
		std::function<void()> m_Function;
		core::ThreadEvent m_ExecThreadEvent;
		core::ThreadEvent m_EndThreadEvent;
	};
	std::vector<ThreadInfo> m_ThreadInfos;
	s32 m_ExecuteCount{};

	static void ThreadFunc(void* _threadInfo);
};

#endif // JOB_SYSTEM_H
