/*****************************************************************//**
 * \file   Thread.h
 * \brief  �X���b�h
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_THREAD_H
#define CANDY_THREAD_H

#include "ThreadDef.h"
#include "ThreadHandle.h"

CANDY_NAMESPACE_BEGIN

class Thread
{
public:
	DEFAULT_CONSTRUCTOR(Thread);
	explicit Thread(const ThreadHandle);
	DELETE_COPY(Thread);
	DEFAULT_MOVE(Thread);

	// �쐬
	void create(std::function<void(void*)> _func, void* _args, const CreateThreadOption _option = CreateThreadOption{});
	// �쐬
	void create(std::function<void()> _func, const CreateThreadOption _option = CreateThreadOption{});
	// ��~
	void suspend();
	// �ĊJ
	void resume();
	// �I���ҋ@
	void wait();

private:
	std::unique_ptr<ThreadFunctionArg> m_ThreadFunctionArgPtr;
	ThreadHandle m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_H
