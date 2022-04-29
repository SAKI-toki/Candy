#ifndef CANDY_THREAD_SYSTEM_IMPL_H
#define CANDY_THREAD_SYSTEM_IMPL_H

#include <Thread/ThreadDef.h>
#include "ThreadHandle.h"

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem::Impl
{
	ThreadHandle CreateThread(ThreadFunctionArg* _pThreadFunctionArg);
	void SuspendThread(const ThreadHandle& _handle);
	void ResumeThread(const ThreadHandle& _handle);
	void WaitThread(const ThreadHandle& _handle);
	s32 GetCurrentThreadId();
	s32 GetCurrentThreadNo();
	ThreadHandle GetCurrentThreadHandle();
	void SetThreadNo(const ThreadHandle _handle, const s32 _no);
	void SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority);
	void SleepThread(const s32 _milliSecond);
}

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_SYSTEM_IMPL_H
