#ifndef CANDY_THREAD_H
#define CANDY_THREAD_H

#include "ThreadDef.h"

#if PLATFORM_WIN
#include "Platform/Win/ThreadHandle.h"
#endif

CANDY_NAMESPACE_BEGIN

class Thread
{
public:
	DEFAULT_CONSTRUCTOR(Thread);
	explicit Thread(const ThreadHandle);
	DELETE_COPY(Thread);
	DEFAULT_MOVE(Thread);

	void create(Function<void(void*)> _func, void* _args, const CreateThreadOption _option = CreateThreadOption{});
	void suspend();
	void resume();
	void wait();

private:
	std::unique_ptr<ThreadFunctionArg> m_ThreadFunctionArgPtr;
	ThreadHandle m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_H
