#include "ThreadSystem.h"

#if PLATFORM_WIN
#include "Platform/Win/ThreadSystemImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

ThreadHandle ThreadSystem::CreateThread(ThreadFunctionArg* _threadFunctionArgPtr)
{
	return Impl::CreateThread(_threadFunctionArgPtr);
}
void ThreadSystem::SuspendThread(const ThreadHandle _handle)
{
	Impl::SuspendThread(_handle);
}
void ThreadSystem::ResumeThread(const ThreadHandle _handle)
{
	Impl::ResumeThread(_handle);
}
void ThreadSystem::WaitThread(const ThreadHandle _handle)
{
	Impl::WaitThread(_handle);
}

s32 ThreadSystem::GetCurrentThreadId()
{
	return Impl::GetCurrentThreadId();
}

s32 ThreadSystem::GetCurrentThreadNo()
{
	return Impl::GetCurrentThreadNo();
}

Thread ThreadSystem::GetCurrentThread()
{
	return Thread{ GetCurrentThreadHandle() };
}

ThreadHandle ThreadSystem::GetCurrentThreadHandle()
{
	return Impl::GetCurrentThreadHandle();
}

void ThreadSystem::SetThreadNo(const ThreadHandle _handle, const s32 _no)
{
	return Impl::SetThreadNo(_handle, _no);
}

void ThreadSystem::SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority)
{
	return Impl::SetPriority(_handle, _priority);
}

void ThreadSystem::SleepThread(const s32 _milliSecond)
{
	Impl::SleepThread(_milliSecond);
}

CANDY_NAMESPACE_END
