/*****************************************************************//**
 * \file   ThreadSystemImpl.h
 * \brief  �X���b�h�V�X�e���̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_THREAD_SYSTEM_IMPL_H
#define CANDY_THREAD_SYSTEM_IMPL_H

#include <Thread/ThreadDef.h>
#include <Thread/ThreadHandle.h>

CANDY_NAMESPACE_BEGIN

namespace ThreadSystem::Impl
{
	// �X���b�h�̍쐬
	ThreadHandle CreateThread(ThreadFunctionArg* _pThreadFunctionArg);
	// �X���b�h�̒�~
	void SuspendThread(const ThreadHandle _handle);
	// �X���b�h�̍ĊJ
	void ResumeThread(const ThreadHandle _handle);
	// �X���b�h�I���ҋ@
	void WaitThread(const ThreadHandle _handle);
	// ���݂̃X���b�hID�̎擾
	s32 GetCurrentThreadId();
	// ���݂̃X���b�h�ԍ��̎擾
	s32 GetCurrentThreadNo();
	// ���݂̃X���b�h�n���h���̎擾
	ThreadHandle GetCurrentThreadHandle();
	// �X���b�h�ԍ��̃Z�b�g
	void SetThreadNo(const ThreadHandle _handle, const s32 _no);
	// �X���b�h�D��x�̃Z�b�g
	void SetPriority(const ThreadHandle _handle, const THREAD_PRIORITY _priority);
	// �X���b�h�X���[�v
	void SleepThread(const s32 _milliSecond);
}

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_SYSTEM_IMPL_H
