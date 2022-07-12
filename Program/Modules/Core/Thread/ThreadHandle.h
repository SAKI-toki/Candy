/*****************************************************************//**
 * \file   ThreadHandle.h
 * \brief  スレッドハンドラ
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_THREAD_HANDLE_H
#define CANDY_CORE_THREAD_HANDLE_H

#include <Core/CoreInclude.h>

#include "ThreadDef.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Thread/ThreadHandleImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

class ThreadHandle : public ThreadHandleImpl
{
public:
	// 閉じる
	void Close();
	// 比較関数群
	bool operator==(const ThreadHandle& _other)const;
	bool operator!=(const ThreadHandle& _other)const;
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_THREAD_HANDLE_H
