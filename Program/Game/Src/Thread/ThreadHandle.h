#ifndef CANDY_THREAD_HANDLE_H
#define CANDY_THREAD_HANDLE_H

#include "ThreadDef.h"

#if PLATFORM_WIN
#include "Platform/Win/ThreadHandleImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

class ThreadHandle : public ThreadHandleImpl
{
public:
	// 閉じる
	void Close();
	// 比較関数群
	bool operator==(const ThreadHandle& _other)const;
	bool operator!=(const ThreadHandle& _other)const;
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_HANDLE_H
