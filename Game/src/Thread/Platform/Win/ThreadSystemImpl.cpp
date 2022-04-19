#include "ThreadSystemImpl.h"

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem::Impl
{
	DWORD WINAPI ThreadFunction(void* _arg);
}

ThreadHandle ThreadSystem::Impl::CreateThread(ThreadFunctionArg* _pThreadFunctionArg)
{
	ThreadHandle handle;
	DWORD creationFlags = 0;
	if (_pThreadFunctionArg->m_Option.m_bSuspend)creationFlags |= CREATE_SUSPENDED;
	handle.setHandle(::CreateThread(nullptr, 0, ThreadFunction, static_cast<void*>(_pThreadFunctionArg), creationFlags, nullptr));
	return handle;
}

void ThreadSystem::Impl::SuspendThread(const ThreadHandle& _handle)
{
	::SuspendThread(_handle.getHandle());
}

void ThreadSystem::Impl::ResumeThread(const ThreadHandle& _handle)
{
	::ResumeThread(_handle.getHandle());
}

void ThreadSystem::Impl::WaitThread(const ThreadHandle& _handle)
{
	::WaitForSingleObjectEx(_handle.getHandle(), INFINITE, false);
}

s32 ThreadSystem::Impl::GetCurrentThreadId()
{
	return ::GetCurrentThreadId();
}

s32 ThreadSystem::Impl::GetCurrentThreadNo()
{
	return ::GetCurrentProcessorNumber();
}

ThreadHandle ThreadSystem::Impl::GetCurrentThreadHandle()
{
	ThreadHandle handle;
	handle.setHandle(::GetCurrentThread());
	return handle;
}

void ThreadSystem::Impl::SetThreadNo(const ThreadHandle _handle, const s32 _no)
{
	::SetThreadAffinityMask(_handle.getHandle(), static_cast<u64>(1) << _no);
}

DWORD WINAPI ThreadSystem::Impl::ThreadFunction(void* _arg)
{
	ThreadFunctionArg* arg = static_cast<ThreadFunctionArg*>(_arg);
	if (arg->m_Option.m_CoreNo != -1)SetThreadNo(GetCurrentThreadHandle(), arg->m_Option.m_CoreNo);
	arg->m_Func(arg->m_Args);
	return 0;
}

CANDY_NAMESPACE_END
