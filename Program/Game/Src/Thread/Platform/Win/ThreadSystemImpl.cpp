/*****************************************************************//**
 * \file   ThreadSystemImpl.cpp
 * \brief  �X���b�h�V�X�e���̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadSystemImpl.h"

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem::Impl
{
	// �X���b�h�N���֐�
	DWORD WINAPI ThreadFunction(void* _arg);
}

// �X���b�h�̍쐬
ThreadHandle ThreadSystem::Impl::CreateThread(ThreadFunctionArg* _pThreadFunctionArg)
{
	ThreadHandle handle;
	DWORD creationFlags = 0;
	if (_pThreadFunctionArg->m_Option.m_bSuspend)creationFlags |= CREATE_SUSPENDED;
	handle.setHandle(::CreateThread(nullptr, 0, ThreadFunction, static_cast<void*>(_pThreadFunctionArg), creationFlags, nullptr));

	return handle;
}

// �X���b�h�̒�~
void ThreadSystem::Impl::SuspendThread(const ThreadHandle _handle)
{
	::SuspendThread(_handle.getHandle());
}

// �X���b�h�̍ĊJ
void ThreadSystem::Impl::ResumeThread(const ThreadHandle _handle)
{
	::ResumeThread(_handle.getHandle());
}

// �X���b�h�I���ҋ@
void ThreadSystem::Impl::WaitThread(const ThreadHandle _handle)
{
	::WaitForSingleObjectEx(_handle.getHandle(), INFINITE, false);
}

// ���݂̃X���b�hID�̎擾
s32 ThreadSystem::Impl::GetCurrentThreadId()
{
	return ::GetCurrentThreadId();
}

// ���݂̃X���b�h�ԍ��̎擾
s32 ThreadSystem::Impl::GetCurrentThreadNo()
{
	return ::GetCurrentProcessorNumber();
}

// ���݂̃X���b�h�n���h���̎擾
ThreadHandle ThreadSystem::Impl::GetCurrentThreadHandle()
{
	ThreadHandle handle;
	handle.setHandle(::GetCurrentThread());
	return handle;
}

// �X���b�h�ԍ��̃Z�b�g
void ThreadSystem::Impl::SetThreadNo(const ThreadHandle _handle, const s32 _no)
{
	::SetThreadAffinityMask(_handle.getHandle(), static_cast<u64>(1) << _no);
}

// �X���b�h�D��x�̃Z�b�g
void ThreadSystem::Impl::SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority)
{
	s32 threadPriority = 0;
	switch (_priority)
	{
	case THREAD_PRIORITY::CRITICAL:	threadPriority = THREAD_PRIORITY_TIME_CRITICAL;	break;
	case THREAD_PRIORITY::HIGHEST:	threadPriority = THREAD_PRIORITY_HIGHEST;		break;
	case THREAD_PRIORITY::NORMAL:	threadPriority = THREAD_PRIORITY_NORMAL;		break;
	case THREAD_PRIORITY::LOWEST:	threadPriority = THREAD_PRIORITY_LOWEST;		break;
	}
	::SetThreadPriority(_handle.getHandle(), threadPriority);
}

// �X���b�h�X���[�v
void ThreadSystem::Impl::SleepThread(const s32 _milliSecond)
{
	::Sleep(static_cast<DWORD>(_milliSecond));
}

// �X���b�h�N���֐�
DWORD WINAPI ThreadSystem::Impl::ThreadFunction(void* _arg)
{
	ThreadFunctionArg* arg = static_cast<ThreadFunctionArg*>(_arg);

	ThreadHandle handle = GetCurrentThreadHandle();

	if (arg->m_Option.m_CoreNo != -1)SetThreadNo(handle, arg->m_Option.m_CoreNo);
	SetPriority(handle, arg->m_Option.m_Priority);

	arg->m_Func(arg->m_Args);
	return 0;
}

CANDY_NAMESPACE_END
