/*****************************************************************//**
 * \file   ThreadEventImpl.h
 * \brief  スレッドイベントの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/11
 *********************************************************************/

#ifndef CANDY_CORE_THREAD_EVENT_IMPL_H
#define CANDY_CORE_THREAD_EVENT_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

class ThreadEventImpl
{
protected:
	CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(ThreadEventImpl);
	CANDY_DELETE_COPY(ThreadEventImpl);
	CANDY_DEFAULT_MOVE(ThreadEventImpl);

	// 初期化
	void startup();
	// 破棄
	void cleanup();
	// シグナル
	void signal();
	// 待機
	void wait();
	// リセット
	void reset();

private:
	HANDLE m_Handle{};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_THREAD_EVENT_IMPL_H
