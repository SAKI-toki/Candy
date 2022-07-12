/*****************************************************************//**
 * \file   ThreadEvent.cpp
 * \brief  スレッドイベント
 * \author Yu Ishiyama.
 * \date   2022/06/11
 *********************************************************************/

#include "ThreadEvent.h"

CANDY_CORE_NAMESPACE_BEGIN

// 初期化
void ThreadEvent::startup()
{
	ThreadEventImpl::startup();
}
// 破棄
void ThreadEvent::cleanup()
{
	ThreadEventImpl::cleanup();
}
// シグナル
void ThreadEvent::signal()
{
	ThreadEventImpl::signal();
}
// 待機
void ThreadEvent::wait()
{
	ThreadEventImpl::wait();
}
// リセット
void ThreadEvent::reset()
{
	ThreadEventImpl::reset();
}

CANDY_CORE_NAMESPACE_END

