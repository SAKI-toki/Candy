/*****************************************************************//**
 * \file   Thread.cpp
 * \brief  スレッド
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "Thread.h"
#include "ThreadSystem.h"

CANDY_NAMESPACE_BEGIN

Thread::Thread(const ThreadHandle _handle):m_Handle{ _handle }
{

}

// 作成
void Thread::create(std::function<void(void*)> _func, void* _args, const CreateThreadOption _option)
{
	m_Handle.Close();
	m_ThreadFunctionArgPtr = std::make_unique<ThreadFunctionArg>();
	m_ThreadFunctionArgPtr->m_Func = _func;
	m_ThreadFunctionArgPtr->m_Args = _args;
	m_ThreadFunctionArgPtr->m_Option = _option;
	m_Handle = ThreadSystem::CreateThread(m_ThreadFunctionArgPtr.get());
}
// 作成
void Thread::create(std::function<void()> _func, const CreateThreadOption _option)
{
	create([_func](void*) { _func(); }, nullptr, _option);
}
// 停止
void Thread::suspend()
{
	ThreadSystem::SuspendThread(m_Handle);
}
// 再開
void Thread::resume()
{
	ThreadSystem::ResumeThread(m_Handle);
}
// 終了待機
void Thread::wait()
{
	ThreadSystem::WaitThread(m_Handle);
	m_Handle.Close();
}

CANDY_NAMESPACE_END
