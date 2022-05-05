#ifndef CANDY_THREAD_SYSTEM_H
#define CANDY_THREAD_SYSTEM_H

#include "ThreadDef.h"
#include "Thread.h"

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem
{
	ThreadHandle CreateThread(ThreadFunctionArg* _threadFunctionArgPtr);
	void SuspendThread(const ThreadHandle _handle);
	void ResumeThread(const ThreadHandle _handle);
	void WaitThread(const ThreadHandle _handle);
	s32 GetCurrentThreadId();
	s32 GetCurrentThreadNo();
	Thread GetCurrentThread();
	ThreadHandle GetCurrentThreadHandle();
	void SetThreadNo(const ThreadHandle _handle, const s32 _no);
	void SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority);
	void SleepThread(const s32 _milliSecond);
}

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_SYSTEM_H
