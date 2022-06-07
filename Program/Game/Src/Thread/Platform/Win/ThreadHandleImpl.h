/*****************************************************************//**
 * \file   ThreadHandleImpl.h
 * \brief  スレッドハンドラの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_THREAD_HANDLE_IMPL_H
#define CANDY_THREAD_HANDLE_IMPL_H

CANDY_NAMESPACE_BEGIN

class ThreadHandleImpl
{
protected:
	// 閉じる
	void Close();

	// 比較関数群
	bool operator==(const ThreadHandleImpl& _other)const;
	bool operator!=(const ThreadHandleImpl& _other)const;

public:
	// ハンドラのセット
	void setHandle(const HANDLE _handle);
	// ハンドラの取得
	HANDLE getHandle()const;

private:
	HANDLE m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_HANDLE_IMPL_H
