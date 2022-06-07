/*****************************************************************//**
 * \file   ThreadHandleImpl.h
 * \brief  �X���b�h�n���h���̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_THREAD_HANDLE_IMPL_H
#define CANDY_THREAD_HANDLE_IMPL_H

CANDY_NAMESPACE_BEGIN

class ThreadHandleImpl
{
protected:
	// ����
	void Close();

	// ��r�֐��Q
	bool operator==(const ThreadHandleImpl& _other)const;
	bool operator!=(const ThreadHandleImpl& _other)const;

public:
	// �n���h���̃Z�b�g
	void setHandle(const HANDLE _handle);
	// �n���h���̎擾
	HANDLE getHandle()const;

private:
	HANDLE m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_HANDLE_IMPL_H
