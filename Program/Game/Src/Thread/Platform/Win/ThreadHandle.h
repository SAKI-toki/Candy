#ifndef CANDY_THREAD_HANDLE_H
#define CANDY_THREAD_HANDLE_H

CANDY_NAMESPACE_BEGIN

class ThreadHandle
{
public:
	void Close();
	void setHandle(const HANDLE _handle);
	HANDLE getHandle()const;

	bool operator==(const ThreadHandle& _other)const;
	bool operator!=(const ThreadHandle& _other)const;

private:
	HANDLE m_Handle{};
};

CANDY_NAMESPACE_END

#endif // CANDY_THREAD_HANDLE_H
