/*****************************************************************//**
 * \file   ThreadSystem.cpp
 * \brief  スレッドシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadSystem.h"

#if PLATFORM_WIN
#include "Platform/Win/ThreadSystemImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

// スレッドの作成
ThreadHandle ThreadSystem::CreateThread(ThreadFunctionArg* _threadFunctionArgPtr)
{
	return Impl::CreateThread(_threadFunctionArgPtr);
}
// スレッドの停止
void ThreadSystem::SuspendThread(const ThreadHandle _handle)
{
	Impl::SuspendThread(_handle);
}
// スレッドの再開
void ThreadSystem::ResumeThread(const ThreadHandle _handle)
{
	Impl::ResumeThread(_handle);
}
// スレッド終了待機
void ThreadSystem::WaitThread(const ThreadHandle _handle)
{
	Impl::WaitThread(_handle);
}

// 現在のスレッドIDの取得
s32 ThreadSystem::GetCurrentThreadId()
{
	return Impl::GetCurrentThreadId();
}

// 現在のスレッド番号の取得
s32 ThreadSystem::GetCurrentThreadNo()
{
	return Impl::GetCurrentThreadNo();
}

// 現在のスレッドの取得
Thread ThreadSystem::GetCurrentThread()
{
	return Thread{ GetCurrentThreadHandle() };
}

// 現在のスレッドハンドルの取得
ThreadHandle ThreadSystem::GetCurrentThreadHandle()
{
	return Impl::GetCurrentThreadHandle();
}

// スレッド番号のセット
void ThreadSystem::SetThreadNo(const ThreadHandle _handle, const s32 _no)
{
	return Impl::SetThreadNo(_handle, _no);
}

// スレッド優先度のセット
void ThreadSystem::SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority)
{
	return Impl::SetPriority(_handle, _priority);
}

// スレッドスリープ
void ThreadSystem::SleepThread(const s32 _milliSecond)
{
	Impl::SleepThread(_milliSecond);
}

CANDY_NAMESPACE_END
