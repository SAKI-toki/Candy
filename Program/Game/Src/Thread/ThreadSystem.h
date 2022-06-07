/*****************************************************************//**
 * \file   ThreadSystem.h
 * \brief  スレッドシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_THREAD_SYSTEM_H
#define CANDY_THREAD_SYSTEM_H

#include "ThreadDef.h"
#include "Thread.h"

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem
{
	// スレッドの作成
	ThreadHandle CreateThread(ThreadFunctionArg* _pThreadFunctionArg);
	// スレッドの停止
	void SuspendThread(const ThreadHandle _handle);
	// スレッドの再開
	void ResumeThread(const ThreadHandle _handle);
	// スレッド終了待機
	void WaitThread(const ThreadHandle _handle);
	// 現在のスレッドIDの取得
	s32 GetCurrentThreadId();
	// 現在のスレッド番号の取得
	s32 GetCurrentThreadNo();
	// 現在のスレッドの取得
	Thread GetCurrentThread();
	// 現在のスレッドハンドルの取得
	ThreadHandle GetCurrentThreadHandle();
	// スレッド番号のセット
	void SetThreadNo(const ThreadHandle _handle, const s32 _no);
	// スレッド優先度のセット
	void SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority);
	// スレッドスリープ
	void SleepThread(const s32 _milliSecond);
}

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_SYSTEM_H
