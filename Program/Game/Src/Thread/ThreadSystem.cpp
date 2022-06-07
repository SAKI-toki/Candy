/*****************************************************************//**
 * \file   ThreadSystem.cpp
 * \brief  �X���b�h�V�X�e��
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#include "ThreadSystem.h"

#if PLATFORM_WIN
#include "Platform/Win/ThreadSystemImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

// �X���b�h�̍쐬
ThreadHandle ThreadSystem::CreateThread(ThreadFunctionArg* _threadFunctionArgPtr)
{
	return Impl::CreateThread(_threadFunctionArgPtr);
}
// �X���b�h�̒�~
void ThreadSystem::SuspendThread(const ThreadHandle _handle)
{
	Impl::SuspendThread(_handle);
}
// �X���b�h�̍ĊJ
void ThreadSystem::ResumeThread(const ThreadHandle _handle)
{
	Impl::ResumeThread(_handle);
}
// �X���b�h�I���ҋ@
void ThreadSystem::WaitThread(const ThreadHandle _handle)
{
	Impl::WaitThread(_handle);
}

// ���݂̃X���b�hID�̎擾
s32 ThreadSystem::GetCurrentThreadId()
{
	return Impl::GetCurrentThreadId();
}

// ���݂̃X���b�h�ԍ��̎擾
s32 ThreadSystem::GetCurrentThreadNo()
{
	return Impl::GetCurrentThreadNo();
}

// ���݂̃X���b�h�̎擾
Thread ThreadSystem::GetCurrentThread()
{
	return Thread{ GetCurrentThreadHandle() };
}

// ���݂̃X���b�h�n���h���̎擾
ThreadHandle ThreadSystem::GetCurrentThreadHandle()
{
	return Impl::GetCurrentThreadHandle();
}

// �X���b�h�ԍ��̃Z�b�g
void ThreadSystem::SetThreadNo(const ThreadHandle _handle, const s32 _no)
{
	return Impl::SetThreadNo(_handle, _no);
}

// �X���b�h�D��x�̃Z�b�g
void ThreadSystem::SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority)
{
	return Impl::SetPriority(_handle, _priority);
}

// �X���b�h�X���[�v
void ThreadSystem::SleepThread(const s32 _milliSecond)
{
	Impl::SleepThread(_milliSecond);
}

CANDY_NAMESPACE_END
