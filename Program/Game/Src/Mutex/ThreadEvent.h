/*****************************************************************//**
 * \file   ThreadEvent.h
 * \brief  スレッドイベント
 * \author Yu Ishiyama.
 * \date   2022/06/11
 *********************************************************************/

#ifndef CANDY_THREAD_EVENT_H
#define CANDY_THREAD_EVENT_H

#if PLATFORM_WIN
#include "Platform/Win/ThreadEventImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

class ThreadEvent : ThreadEventImpl
{
public:
	CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(ThreadEvent);
	CANDY_DELETE_COPY(ThreadEvent);
	CANDY_DEFAULT_MOVE(ThreadEvent);

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
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_EVENT_H
