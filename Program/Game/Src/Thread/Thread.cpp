#include "Thread.h"
#include "ThreadSystem.h"

CANDY_NAMESPACE_BEGIN

Thread::Thread(const ThreadHandle _handle):m_Handle{ _handle }
{

}

void Thread::create(std::function<void(void*)> _func, void* _args, const CreateThreadOption _option)
{
	m_Handle.Close();
	m_ThreadFunctionArgPtr = std::make_unique<ThreadFunctionArg>();
	m_ThreadFunctionArgPtr->m_Func = _func;
	m_ThreadFunctionArgPtr->m_Args = _args;
	m_ThreadFunctionArgPtr->m_Option = _option;
	m_Handle = ThreadSystem::CreateThread(m_ThreadFunctionArgPtr.get());
}
void Thread::create(std::function<void()> _func, const CreateThreadOption _option)
{
	create([_func](void*) { _func(); }, nullptr, _option);
}
void Thread::suspend()
{
	ThreadSystem::SuspendThread(m_Handle);
}
void Thread::resume()
{
	ThreadSystem::ResumeThread(m_Handle);
}
void Thread::wait()
{
	ThreadSystem::WaitThread(m_Handle);
	m_Handle.Close();
}

CANDY_NAMESPACE_END
