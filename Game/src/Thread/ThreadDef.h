#ifndef CANDY_THREAD_DEF_H
#define CANDY_THREAD_DEF_H

#include <Function/Function.h>

CANDY_NAMESPACE_BEGIN

struct CreateThreadOption
{
	bool m_bSuspend = false;
	s32 m_CoreNo = -1;
};

struct ThreadFunctionArg
{
	Function<void(void*)> m_Func;
	void* m_Args = nullptr;
	CreateThreadOption m_Option{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_DEF_H
