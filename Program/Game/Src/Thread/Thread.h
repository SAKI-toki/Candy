/*****************************************************************//**
 * \file   Thread.h
 * \brief  スレッド
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
	CANDY_DEFAULT_CONSTRUCTOR(Thread);
	explicit Thread(const ThreadHandle);
	CANDY_DELETE_COPY(Thread);
	CANDY_DEFAULT_MOVE(Thread);

	// 作成
	void create(std::function<void(void*)> _func, void* _args, const CreateThreadOption _option = CreateThreadOption{});
	// 作成
	void create(std::function<void()> _func, const CreateThreadOption _option = CreateThreadOption{});
	// 閉じる
	void close();
	// 停止
	void suspend();
	// 再開
	void resume();
	// 終了待機
	void wait();

private:
	std::unique_ptr<ThreadFunctionArg> m_ThreadFunctionArgPtr;
	ThreadHandle m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_H
